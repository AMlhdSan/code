/*
线段树维护区间最大/小值就是按照原来给出的数据的顺序建造一颗二叉树，然后每一个节点维护
这个节点的子节点且包含这个节点的值中的最大/小值
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int MAX_LEN =1000 ;
int seg_tree[MAX_LEN << 2];
int Lazy[MAX_LEN << 2];
int arr[MAX_LEN];
int opt, lll, rrr;
//从下往上更新 节点
void push_up (int root) {
    seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //最小值改min
}
//从上向下更新，左右孩子
void push_down (int root, int L, int R) {
    if(Lazy[root]){
        Lazy[root << 1] += Lazy [root];
        Lazy[root << 1 | 1] += Lazy[root];
        int mid = (L + R) >> 1;
        seg_tree[root << 1] +=  Lazy[root] * (mid - L + 1);
        seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
        Lazy[root] = 0;
    }
}
//建树
//[L,R]就是对应arr数组里面的数
void build (int root, int L, int R) {
    Lazy[root] = 0;
    if(L == R) {
        seg_tree[root] = arr[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(root << 1, L, mid);
    build(root << 1 | 1, mid + 1, R);
    push_up(root);
}

//区间查询
//查找区间[LL,RR]的最大/小值
int query (int root, int L, int R, int LL, int RR) {
    if (LL <= L && R <= RR) return seg_tree[root];
    push_down(root, L, R);     //每次访问都去检查Lazy 标记
    int Ans = 0;
    int mid = (L + R) >> 1;
    if(LL <= mid) Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //最小值改min
    if(RR > mid) Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //最小值改min
    return Ans;
}
void update(int root, int L, int R, int pos, int val) {
    if(L == R){
        seg_tree[root] = val;
        return ;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) update(root << 1, L, mid, pos, val);
    else update(root << 1 | 1, mid + 1, R, pos, val);
    push_up(root);
}
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    int n, m, q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int t = query(1, 1, n, l, r);
        for(int i = l; i <= r; ++i) {
            update(1, 1, n, i, i, t);
        }
    }
    scanf("%d", &q);
    while(q--) {
        opt = read();
        lll = read();
        rrr = read();
        write(query(1, 1, n, lll, r))
    }

    return 0;
}