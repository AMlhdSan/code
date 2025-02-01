#include <iostream>
#include <vector>
using namespace std;
 
struct BIT {
    int n;
    vector<int> t;
    BIT(int n): n(n), t(n+1,0) {}
    void upd(int i, int d) { for(; i<=n; i+= i&-i) t[i]+=d; }
    int qry(int i) { int s=0; for(; i; i-= i&-i) s+= t[i]; return s; }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q; // 此分支要求 m==0
    vector<int> Qv(q);
    for (int i=0; i<q; i++) cin >> Qv[i];
    // 将 BIT 长度设为 n+q，用以记录动态位置
    int size = n+q;
    BIT bit(size);
    vector<int> pos(n+1);
    // 初始：鞋 i 在位置 i（1-index）
    for (int i=1; i<=n; i++){
        pos[i] = i;
        bit.upd(i, 1);
    }
    int cur = n;
    long long ans = 0;
    for (int i=0; i<q; i++){
        int a = Qv[i];
        int p = pos[a];
        int cnt = bit.qry(p);
        ans += cnt;
        bit.upd(p, -1);
        cur++;
        pos[a] = cur;   // 放到衣柜顶端（位置为最新的 cur）
        bit.upd(pos[a], 1);
    }
    cout << ans << "\n";
    return 0;
}
