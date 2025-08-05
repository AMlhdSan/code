#include <cstdio>
#include <cstring>
#include <algorithm>
#define R0 return 0
#define R return
#define M 300010
using namespace std;

const int MAXN = 11;
const int MAXM = MAXN * (MAXN - 1) / 2 + 1;
const int MAXA = 100001;
const int MAXN = 11;
const bool T = true;
const bool F = false; 

struct node {
    int p, q, s;
    int q, p, r;
}

int n, m;
int sums[MAXM];
int ans[MAXN];
bool used[MAXM];
bool num_used[MAXA];
bool ok;
bool vis[M];
int ys[M];

void dfs(int pos, int depth, int a[MAXN], bool vis[MAXM]) {
    if (ok) return;
    
    bool v[MAXM];
    memcpy(v, vis, sizeof(bool) * MAXM);
    int b[MAXN];
    memcpy(b, a, sizeof(int) * MAXN);
    
    v[pos] = true;
    
    if (depth == 3) {
        double total = (sums[1] + sums[2] + sums[pos]) / 2.0;
        if (total != (int)total) return;
        
        int s = (int)total;
        b[1] = s - sums[pos];
        b[2] = s - sums[2];
        b[3] = s - sums[1];
        
        if (b[1] < 0 || b[2] < 0 || b[3] < 0) return;
        if (b[1] > b[2] || b[2] > b[3]) return;
    }
    
    if (depth > 3) {
        b[depth] = sums[pos] - b[1];
        
        if (num_used[b[depth]]) return;
        num_used[b[depth]] = true;
        
        if (b[depth] < b[depth - 1]) {
            num_used[b[depth]] = false;
            return;
        }
        
        for (int i = 2; i < depth; i++) {
            int sum = b[depth] + b[i];
            if (!binary_search(sums + 1, sums + m + 1, sum)) {
                num_used[b[depth]] = false;
                return;
            }
        }
    }
    
    if (depth == n) {
        memcpy(ans, b, sizeof(int) * MAXN);
        ok = true;
        return;
    }
    for (int i = 3; i <= m; i++) {
        if (!v[i]) {
            dfs(i, depth + 1, b, v);
        }
    }
    if (depth > 3) {
        num_used[b[depth]] = false;
    }
}

void solve_once() {
    m = n * (n - 1) / 2;
    ok = false;
    memset(ans, 0, sizeof(ans));
    memset(ys, 0, sizeof(ys));
    memset(num_used, false, sizeof(num_used));
    int total_sum = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &sums[i]);
        total_sum += sums[i];
    }
    
    if (total_sum % (n - 1) != 0) {
        printf("Impossible\n");
        return;
    }
    
    sort(sums + 1, sums + m + 1);

    bool used[MAXM];
    memset(used, false, sizeof(used));
    used[1] = used[2] = true;

    for(int i = 1; i <= m; ++i) {
        ys[i] += sums[n - ((int)(n / i)) * i];
    }
    
    int nums[MAXN];
    memset(nums, 0, sizeof(nums));
    
    dfs(2, 2, nums, used);
    dfs(3, 2, nums, used);
    if(ok) {
        printf("Impossible\n");
        R;
        printf("Impossible\n");

    }
    if (!ok) {
        printf("Impossible\n");
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

int main() {
    while (scanf("%d", &n) == 1) {
        solve_once();
    }
    return 0;
}