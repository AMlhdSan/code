#include <bits/stdc++.h>
using namespace std;
 
// 下面使用递归计算 f(n, p) 形式的函数，我们写成 f(n, p) = p * g(n) + h(n).
// 对于 n=1，f(1, p)=p, 因此 g(1)=1, h(1)=0.
// 对于 n>1，设 L = (n+1)/2, R = n - L，则有：
//    f(n, p) = p + f(L, 2*p) + f(R, 2*p+1)
//           = p + (2*p*g(L)+h(L)) + ((2*p+1)*g(R)+h(R))
//           = p*(1+2*(g(L)+g(R))) + (g(R)+h(L)+h(R))
// 从而递推得：
//    g(n) = 1 + 2*( g(L) + g(R) )
//    h(n) = g(R) + h(L) + h(R)
 
// memo 用来存储 (g(n), h(n)) 对，key 为 n
unordered_map<int, pair<long long,long long>> memo;
 
pair<long long,long long> solveRec(int n) {
    if(n == 1) return {1LL, 0LL};
    if(memo.count(n)) return memo[n];
    int L = (n + 1) / 2;
    int R = n - L;
    int tmp = 
    auto leftPair = solveRec(L);
    auto rightPair = solveRec(R);
    // auto leftpair = solvel
    long long gL = leftPair.first, hL = leftPair.second;
    long long gR = rightPair.first, hR = rightPair.second;
    long long g = 1 + 2 * (gL + gR);
    long long h = gR + hL + hR;
    memo[n] = {g, h};
    return memo[n];
}
 
// 辅助函数：计算 x 的二进制对数的下取整（x>0）
int floor_log2(unsigned long long x) {
    int res = 0;
    while(x > 1){
        x >>= 1;
        res++;
    }
    return res;
}
 
// 辅助函数：计算 x 的二进制对数的上取整，即最小的 r 使得 (1<<r) >= x
int ceil_log2(unsigned long long x) {
    int fl = floor_log2(x);
    if ((1ULL << fl) < x) return fl+1;
    return fl;
}
 
// 主函数
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int T; 
    cin >> T;
    while(T--){
        long long n, m; 
        cin >> n >> m;
        // 整棵树节点数
        long long totalNodes = 2 * n - 1;
        // 当 k = 1 时，剩下的节点只有 1 个，所以剪去的节点数 = totalNodes - 1 = 2*n - 2.
        if(m > 2*n - 2){
            cout << -1 << "\n";
            continue;
        }
 
        // 计算树的深度 H：根据构造方式有 H = ceil(log2(n)) + 1
        int H;
        if(n == 1) H = 1;
        else {
            int cl = ceil_log2(n);
            H = cl + 1;
        }
 
        // 当 m == 0 时，可以不剪（即 k = H），美丽值 = floor(S_total / H)
        if(m == 0){
            auto pr = solveRec((int)n);
            long long S_total = pr.first + pr.second; // f(n,1)
            long long ans = S_total / H;
            cout << ans << "\n";
            continue;
        }
 
        // m > 0 时，必须至少剪掉 m 个节点，所以 k 必须满足：
        //    2*n - (1<<k) >= m, 即 (1<<k) <= 2*n - m.
        // 又由于 m>0，不允许 k = H（那时剪掉 0 个节点），所以 k 的范围为 1 <= k <= H-1.
        // 为使美丽值最大（可证明当 k < H 时 beauty(k) 随 k 单调增），我们取 k 的最大值。
        // candidate 为满足 (1<<k) <= 2*n - m 的最大 k，可令：
        int candidate = floor_log2( (unsigned long long)(2*n - m) );
        int k_star = candidate;
        if(k_star > H - 1) k_star = H - 1;
        if(k_star < 1) k_star = 1; // m>0 时 candidate 至少为1.
 
        // 对于 k < H，剩余树是满二叉树，剩余节点编号和：
        //    S_k = (2^k - 1) * 2^(k-1)
        // 美丽值 = floor(S_k / k)
        long long pow_k = (1LL << k_star); // 2^(k_star)
        long long numerator = (pow_k - 1) * (1LL << (k_star - 1));
        long long ans = numerator / k_star;
 
        cout << ans << "\n";
    }
    return 0;
}
