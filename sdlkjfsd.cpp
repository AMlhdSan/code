#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007;
 
// 矩阵类（行优先存储）
struct Matrix {
    int n, m;
    vector<vector<ll>> mat;
    Matrix(int n, int m): n(n), m(m) {
        mat.assign(n, vector<ll>(m, 0));
    }
};
 
// 矩阵乘法
Matrix multiply(const Matrix &A, const Matrix &B) {
    Matrix C(A.n, B.m);
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < B.m; j++) {
            __int128 sum = 0;
            for (int k = 0; k < A.m; k++) {
                sum += A.mat[i][k] * B.mat[k][j];
            }
            C.mat[i][j] = (ll)(sum % MOD);
        }
    }
    return C;
}
 
// 矩阵快速幂
Matrix power(Matrix base, ll exp) {
    Matrix res(base.n, base.m);
    for (int i = 0; i < base.n; i++)
        res.mat[i][i] = 1;
    while(exp){
        if(exp & 1)
            res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}
 
// 快速幂计算 base^exp mod MOD
ll modexp(ll base, ll exp) {
    ll res = 1 % MOD;
    base %= MOD;
    while(exp){
        if(exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
 
// 数据生成函数，当 n > 10 时调用
void gen(int n, unsigned long long seed, ll a[], ll b[], ll c[]){
    mt19937_64 rnd(seed);
    for (int i = 1; i <= n; i++){
        a[i] = rnd() % (ll(1e18)) + 1;
        b[i] = rnd() % (ll(1e9)) + 1;
        c[i] = rnd() % (ll(1e9)) + 1;
    }
}
 
// 全局数组（下标从1开始）
const int MAXN = 2000005;
ll a_arr[MAXN], b_arr[MAXN], c_arr[MAXN];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while(T--){
        int n, a_req, b_req;
        cin >> n >> a_req >> b_req;
        ll V = 0; // 本题中 V 表示螺丝总数，此题无此变量，此处仅遵循题意说明输出答案
        // 当 n <= 10 时直接读入 a, b, c（此处仅用作区分输入格式，与本题实际无关）
        if(n <= 10){
            for (int i = 1; i <= n; i++){
                cin >> a_arr[i] >> b_arr[i] >> c_arr[i];
            }
        } else {
            unsigned long long seed;
            cin >> seed;
            gen(n, seed, a_arr, b_arr, c_arr);
        }
 
        // 本题考察二进制串问题：
        // 对所有长度为 n 的二进制串，要求包含至少一段连续 0 长度 ≥ a_req
        // 或至少包含一段连续 1 长度 ≥ b_req。
        // 答案 = 2^n - (不含连续 0^a_req 且不含连续 1^b_req 的二进制串数) mod MOD.
 
        // 自动机状态数 d = a_req + b_req - 1.
        int d = a_req + b_req - 1;
        // 构造转移矩阵 M (d * d)
        // 状态编号：
        // 0: 空串状态 S0
        // 1 ~ a_req-1: 状态 Z_i 表示末尾连续 0 的个数 = i (i < a_req)
        // a_req ~ (a_req+b_req-2): 状态 O_j 表示末尾连续 1 的个数 = j (j < b_req)
        Matrix M(d, d);
        // 从状态 0: S0
        if(d > 1) {
            // '0' -> Z_1 (状态 1)
            M.mat[0][1] = 1;
            // '1' -> O_1 (状态 a_req,注意 a_req 范围  <= d-1)
            if(a_req < d) M.mat[0][a_req] = 1;
        }
        // 从零状态 Z_i, i=1..a_req-1:
        for (int i = 1; i < a_req; i++){
            // 若 i < a_req-1，则 '0' -> Z_{i+1}
            if(i < a_req - 1) {
                M.mat[i][i+1] = 1;
            }
            // 无论如何，'1' 都能转到 O_1 (状态 a_req)
            if(a_req < d) M.mat[i][a_req] = 1;
        }
        // 从一状态 O_j, j=1..b_req-1:
        for (int j = 1; j < b_req; j++){
            int state = a_req + j - 1; // state 对应 O_j
            // 若 j < b_req-1，则 '1' -> O_{j+1}: O_{j+1} 的编号为 a_req + j
            if(j < b_req - 1) {
                M.mat[state][a_req + j] = 1;
            }
            // '0' 转到 Z_1 (状态 1)
            M.mat[state][1] = 1;
        }
 
        // 计算 f(n) = 从初始状态 S0 出发经过 n 次转移的所有状态的方案数和 = (M^n)[0][*]
        Matrix Tmat = power(M, n);
        ll f_n = 0;
        for (int i = 0; i < d; i++){
            f_n = (f_n + Tmat.mat[0][i]) % MOD;
        }
 
        // 总字符串数 = 2^n mod MOD
        ll total = modexp(2, n);
        // 答案 = total - f(n) (若结果为负加 MOD)
        ll res = (total - f_n + MOD) % MOD;
        cout << res << "\n";
        
    }
    return 0;
}