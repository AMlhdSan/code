#include <bits/stdc++.h>
using namespace std;
// const long long MOD = 998244353;

int n, k;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;      
        ch = getchar();
        gets(ch);
    }

    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }

    return x * f;
}
inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }

    if (x > 9)
        write(x / 10);

    putchar(x % 10 + '0');
}
inline void writeln(int x) {
    write(x);
    putchar('\n');
}
struct Edge {
    int to, c;
};

int main() {
    // freopen("icefire.in", "r", stdin);
    // freopen("icefire.out", "w", stdout);
    int n = read(), m = read();
    vector<vector<Edge>> g(n + 1);
    g[0].clear();
    g[0].resize(n + 1);
    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), t = read();
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }

    for (int i = 1; i <= n; i++) {
        int cnt0 = 0, cnt1 = 0;

        for (auto &e : g[i]) {
            if (e.c == 0)
                cnt0++;
            else
                cnt1++;
        }

        if (cnt0 > 1 || cnt1 > 1) {
            printf("0");
            return 0;
        }
    }

    vector<bool> vis(n + 1, false);
    unordered_map<long long, pair<int, int>> mp;
    auto encode = [&](int t, int p) -> long long {
        return (long long)t * 1000000LL + p;
    };
    auto add = [&](int t, int p, int a) {
        long long key = encode(t, p);

        if (mp.find(key) == mp.end()) {
            mp[key] = {1, a};
        } 
        else {
            mp[key].first++;
        }
    };
    vector<long long> fac(n + 1, 1);

    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % MOD;

    auto modexp = [&](long long b, int e) -> long long{
        long long r = 1;

        while (e) {
            if (e & 1)
                r = (r * b) % MOD;
            if (b < 0)
                b = (b + MOD) % MOD;
            b = (b * b) % MOD;
            e >>= 1;
        }

        return r;
    };
    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> comp;
            queue<int> qu;
            vis[i] = true;
            qu.push(i);

            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();
                comp.push_back(u);

                for (auto &e : g[u]) {
                    int v = e.to;

                    if (!vis[v]) {
                        vis[v] = true;
                        qu.push(v);
                    }
                }
            }

            if (comp.size() == 1) {
                add(0, 0, 1);
                continue;
            }

            bool cyc = true;

            for (auto u : comp) {
                if (g[u].size() != 2) {
                    cyc = false;
                    break;
                }
            }

            if (cyc) {
                int L = comp.size();

                if (L & 1) {
                    printf("0");
                    return 0;
                }

                for (auto u : comp) {
                    if (g[u][0].c == g[u][1].c) {
                        printf("0");
                        return 0;
                    }
                }

                add(3, L, L);
            } else {
                int start = -1;

                for (auto u : comp) {
                    if (g[u].size() == 1) {
                        start = u;
                        break;
                    }
                }

                if (start == -1) {
                    printf("0");
                    return 0;
                }

                vector<int> seq;
                int cur = start, pre = -1;

                while (true) {
                    int nxt = -1, col = -1;

                    for (auto &e : g[cur]) {
                        if (e.to == pre)
                            continue;

                        nxt = e.to;
                        col = e.c;
                    }

                    if (nxt == -1)
                        break;

                    seq.push_back(col);
                    pre = cur;
                    cur = nxt;
                }

                int L = seq.size();

                if (L == 1) {
                    add(1, seq[0], 2);
                } else {
                    for (int j = 0; j + 1 < L; j++) {
                        if (seq[j] == seq[j + 1]) {
                            printf("0");
                            return 0;
                        }
                    }

                    int a = (L & 1) ? 2 : 1;
                    add(2, L, a);
                }
            }
        }
    }

    for (auto &p : mp) {
        int cnt = p.second.first, a = p.second.second;
        ans = (ans * fac[cnt]) % MOD;
        ans = (ans * modexp(a, cnt)) % MOD;
    }

    printf("%lld", ans);
    return 0;
}