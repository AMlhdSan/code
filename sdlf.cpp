#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NEG = -1000000000000000000LL;
 
struct Node {
    ll s, pre, suf, best, ans;
};
 
Node combine(Node L, Node R) {
    Node res;
    res.s = L.s + R.s;
    res.pre = max(L.pre, L.s + R.pre);
    res.suf = max(R.suf, R.s + L.suf);
    res.best = max({L.best, R.best, L.suf + R.pre});
    res.ans = max({L.ans, R.ans, L.suf + R.pre, L.best + R.best});
    return res;
}
 
Node make_data(ll val) {
    Node res;
    res.s = val;
    res.pre = val;
    res.suf = val;
    res.best = val;
    res.ans = val;
    return res;
}
 
struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(int sz) {
        n = 1; 
        while(n < sz) n *= 2;
        tree.assign(2 * n, make_data(0));
    }
    void build(const vector<ll>& arr) {
        int sz = arr.size();
        for (int i = 0; i < sz; i++) {
            tree[n + i] = make_data(arr[i]);
        }
        for (int i = sz; i < n; i++) {
            tree[n + i] = make_data(NEG);
        }
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
        }
    }
    Node query(int l, int r) {
        Node leftRes = make_data(NEG), rightRes = make_data(NEG);
        bool leftSet = false, rightSet = false;
        l += n; r += n;
        while(l <= r) {
            if(l % 2 == 1) {
                if(!leftSet) { leftRes = tree[l]; leftSet = true; }
                else leftRes = combine(leftRes, tree[l]);
                l++;
            }
            if(r % 2 == 0) {
                if(!rightSet) { rightRes = tree[r]; rightSet = true; }
                else rightRes = combine(tree[r], rightRes);
                r--;
            }
            l /= 2; r /= 2;
        }
        if(!leftSet) return rightRes;
        if(!rightSet) return leftRes;
        return combine(leftRes, rightRes);
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> B(2 * n);
    for (int i = 0; i < 2 * n; i++){
        B[i] = a[i % n];
    }
    SegTree seg(2 * n);
    seg.build(B);
    ll ans = NEG;
    for (int L = 0; L < n; L++){
        int R = L + n - 1;
        Node ret = seg.query(L, R);
        ans = max(ans, ret.ans);
    }
    cout << ans << "\n";
    return 0;
}
// 建一个换装线段树，struct 封装。