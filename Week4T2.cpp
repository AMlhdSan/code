#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#define fuck(x) cout<<#x<<" = "<<x<<endl;
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100005;
const int inf = 2.1e9;
const ll Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);
int a[2][maxn];
struct node
{
    string s,t;
    int m,id;
}ss[maxn];
int n;

int lowbit(int x)
{
    return x&(-x);
}

int query(int m,int x){
    int ans=0;
    while(x){
        ans = max(ans,a[m][x]);
        x-=lowbit(x);
    }
    return ans;
}

void add(int m,int x,int num)
{
    while(x<=n){
        a[m][x]=max(a[m][x],num);
        x+=lowbit(x);
    }
}

bool cmp(node a,node b)
{
    return a.s<b.s;
}

bool jud(node a,node b)
{
    return a.t<b.t;
}

int main() {

    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ss[i].s;
        int siz = ss[i].s.size();
        ss[i].t = ss[i].s;
        ss[i].m = 0;
        for(int j=0;j<siz;j++){
            if(ss[i].s[j]=='m'){ss[i].m=1;break;}
        }
        reverse(ss[i].t.begin(),ss[i].t.end());
    }
    sort(ss+1,ss+1+n,cmp);
    for(int i=1;i<=n;i++){
        ss[i].id=i;
    }
    sort(ss+1,ss+1+n,jud);
    int ans = 0;

    for(int i=1;i<=n;i++){
        int tmp;
        tmp = query(ss[i].m^1,ss[i].id)+1;
        ans = max(tmp,ans);
        add(ss[i].m,ss[i].id,tmp);
    }
    cout<<ans<<endl;
    return 0;
}