#include<bits/stdc++.h>

#define int long long
#define N 100010

using namespace std;

int a[N];
int dp[N][4][4];
int vis[N][4][4];
int cur=2;
int n;
int t;

int solve(int idx,int prv1,int prv2) {
    if(idx == n)
        return 0;
    int &ans = dp[idx][prv1][prv2];
    int &v = vis[idx][prv1][prv2];
    if(v == cur)
        return ans;
    v = cur;
    ans = 4e18;
    for(int i=0;i<3;i++)
    {
        int x=a[idx];
        int c=0;
        while(x%3!=i)x++,c++;
        if(prv1==3)ans=min(ans,solve(idx+1,i,prv2)+c);
        else if(prv2==3)ans=min(ans,solve(idx+1,prv1,i)+c);
        else
        {
            if((i+prv1+prv2)%3==0)
            {
                ans=min(ans,solve(idx+1,prv2,i)+c);
            }
        }
    }
    return ans;
}
void solve() {
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cur++;
    int ans=4e18;
    ans=min(ans,solve(0,3,3));
    cout<<ans<<endl;
}
signed main() {
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}