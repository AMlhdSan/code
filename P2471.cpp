#include <bits/stdc++.h>

#define N 500001

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)


using namespace std;

int n, m;
int num[N];
int ll[N];
int rr[N];

int y[N];
int a[N];
bool f[N];
struct Tree{
    int ans,f;
};

void upd(int p) {
    if(rr[ls] == ll[rs] - 1)
        f[p] = f[ls] & f[rs];
    rr[p] = rr[rs];
    ll[p]=ll[ls];
    num[p] = max(num[ls], num[rs]);
}

void build(int p, int l, int r){
    if(l == r) {
        rr[p] = ll[p] = y[l];
        num[p] = a[l];
        f[p] = 1;
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);
    
    upd(p);
}

Tree qry(int ql,int qr,int l,int r,int p){
    if(ql <= l && qr >= r){
        Tree tmp;
        tmp.ans=num[p],tmp.f=f[p];
        return tmp;
    }
    Tree tmp;
    tmp.ans=0;
    tmp.f=1;
    if(ql <= m){
        Tree x = qry(1, l, mid, ql, qr);
        tmp.ans = max(tmp.ans,x.ans);
        tmp.f &= x.f;
    }
    if(qr > m) {
        Tree x = qry(1, mid + 1, r, ql, qr);
        tmp.ans=max(tmp.ans, x.ans);
        tmp.f &= x.f;
    }
    return tmp;
}

int main() {

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> y[i] >> a[i];
    }
    
    build(1, 1, n);
    
    cin >> m;
    while(m--) {
        
        int x, t;
        
        cin >> x >> t;

        if(x >= t) {
            cout << "false" << endl;
            continue;
        }
        int st = lower_bound(y + 1, y + n + 1, x) - y;
        int ed = lower_bound(y + 1, y + n + 1, t) - y;
        bool fl, fr;
        int op = 0;
        fl = y[st] == x;
        fr = y[ed] == t;
        if(!fl)
            --st;
        if(st + 1 <= ed - 1)
            op = qry(1, 1, n, st + 1, ed - 1).ans;
        if((op >= a[ed] && fr) || (a[st] < a[ed] && fl && fr) || (op >= a[st] && fl))
            cout << "false" << endl;
        else if(ed - st != y[ed] - y[st] || !fr || !fl)
            cout << "maybe" << endl;
        else 
            cout << "true" << endl;
    }
    return 0;
}