#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 998244353;
const int MAX_BITS = 60;

// 线性基结构
struct LinearBasis {
    vector<long long> basis;

    LinearBasis() : basis(MAX_BITS, 0) {}

    void insert(long long val) {
        for (int i = MAX_BITS - 1; i >= 0; --i) {
            if (!(val & (1LL << i))) continue;
            if (!basis[i]) {
                basis[i] = val;
                return;
            }
            val ^= basis[i];
        }
    }

    bool can_represent(long long val) const {
        for (int i = MAX_BITS - 1; i >= 0; --i) {
            if (!(val & (1LL << i))) continue;
            if (!basis[i]) return false;
            val ^= basis[i];
        }
        return true;
    }
    
    int get_dim() const {
        int count = 0;
        for(long long b : basis) {
            if (b > 0) count++;
        }
        return count;
    }
};

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    freopen("xortree.in","r",stdin);
    freopen("xortree.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k0;
    int q;
    cin >> k0 >> q;

    vector<long long> X;
    vector<LinearBasis> prefix_bases;
    vector<int> prefix_dims;
    vector<long long> p2;

    p2.push_back(1);
    for (int i = 1; i <= q; ++i) {
        p2.push_back((p2.back() * 2) % MOD);
    }

    // 初始状态，维度为0的空基
    prefix_bases.push_back(LinearBasis());
    prefix_dims.push_back(0);


    for (int op_idx = 0; op_idx < q; ++op_idx) {
        int type;
        cin >> type;
        if (type == 1) {
            long long x;
            cin >> x;
            X.push_back(x);
            LinearBasis new_basis = prefix_bases.back();
            new_basis.insert(x);
            prefix_bases.push_back(new_basis);
            prefix_dims.push_back(new_basis.get_dim());
        } else {
            long long z;
            cin >> z;
            long long total_ans = 0;
            int m = X.size();

            if (m == 0) {
                if (k0 == z) {
                    total_ans = 1;
                }
            } else {
                // 1. 根节点
                if ((k0 ^ X[0]) == z) {
                    total_ans = 1;
                }

                // 2. 内部节点
                for (int i = 1; i < m; ++i) {
                    // 由操作 x_i (即 X[i-1]) 创建, 经历 x_{i+1} (即 X[i]) 扩张
                    const auto& basis_before = prefix_bases[i-1];
                    int dim_before = prefix_dims[i-1];
                    long long count_multiplier = p2[ (i - 1) - dim_before ];

                    // a) 节点权值 = 父节点权值
                    long long target_val_a = z ^ X[i];
                    if (basis_before.can_represent(target_val_a ^ k0)) {
                        total_ans = (total_ans + count_multiplier) % MOD;
                    }

                    // b) 节点权值 = 父节点权值 ^ x_i
                    long long target_val_b = z ^ X[i] ^ X[i-1];
                    if (basis_before.can_represent(target_val_b ^ k0)) {
                        total_ans = (total_ans + count_multiplier) % MOD;
                    }
                }

                // 3. 叶子节点 (由操作 x_m 即 X[m-1] 创建)
                const auto& basis_m = prefix_bases[m];
                int dim_m = prefix_dims[m];
                long long count_multiplier = p2[m - dim_m];
                
                if (basis_m.can_represent(z ^ k0)) {
                    total_ans = (total_ans + count_multiplier) % MOD;
                }
            }
            cout << total_ans << "\n";
        }
    }

    return 0;
}