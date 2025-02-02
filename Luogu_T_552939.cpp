#include <bits/stdc++.h>
using namespace std;
 
const int INF = 0x3f3f3f3f;
 
struct Fenw {
    int n;
    vector<int> f;
    Fenw(int n): n(n), f(n+1, INF) {}
    void upd(int i, int v) {
        for(; i<=n; i+= i&-i) f[i] = min(f[i], v);
    }
    int qry(int i) {
        int r = INF;
        for(; i; i-= i&-i) r = min(r, f[i]);
        return r;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    vector<int> L(n+1, INF);
    Fenw F(n);
    for (int i=1;i<=n;i++){
        if(i <= a[i]) L[i] = 1;
        else {
            int x = F.qry(i - a[i]);
            if(x != INF) L[i] = x + 1;
        }
        F.upd(i, L[i]);
    }
    vector<int> LM(n+2, INF);
    LM[n+1] = INF;
    for (int i=n;i>=1;i--) LM[i] = min(L[i], LM[i+1]);
    int sz = 1; while(sz < n+1) sz *= 2;
    vector<int> S(2*sz, INF);
    auto updS = [&](int p, int v){
        p += sz;
        S[p] = v;
        for(p /=2; p; p /=2) S[p] = min(S[2*p], S[2*p+1]);
    };
    auto qryS = [&](int l, int r) -> int {
        int rtv = INF;
        l += sz; r += sz;
        while(l <= r){
            if(l & 1) { rtv = min(rtv, S[l]); l++; }
            if(!(r & 1)) { rtv = min(rtv, S[r]); r--; }
            l /=2; r /=2;
        }
        return rtv;
    };
    vector<int> R(n+2, INF);
    for (int i=n;i>=1;i--){
        if(i + a[i] - 1 >= n) R[i] = 1;
        else {
            int l = i + a[i], r = n;
            int x = qryS(l, r);
            if(x != INF) R[i] = x + 1;
        }
        updS(i, R[i]);
    }
    vector<int> RM(n+2, INF);
    RM[0] = INF;
    for (int i=1;i<=n;i++){
        if(i==1) RM[i] = R[i];
        else RM[i] = min(RM[i-1], R[i]);
    }
    int ans = INF;
    ans = min(ans, L[n]);
    ans = min(ans, R[1]);
    for (int x=1;x<=n-1;x++){
        if(LM[x]==INF || RM[x+1]==INF) continue;
        ans = min(ans, LM[x] + RM[x+1]);
    }
    cout << (ans==INF? -1 : ans) << "\n";
    return 0;
}
