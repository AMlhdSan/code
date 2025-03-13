#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 200010
#define MAX 300000
#define gc getchar
#define pc putchar
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)

int a[N];
int spf[MAX + 1];
int primes[N][50];  // 假设每个数最多有50个不同质因子
int primeSize[N];
int primeToSpiders[MAX + 1][N];
int primeToSpidersSize[MAX + 1];
int dist[N], par[N];
bool vis[N], used[MAX + 1];
int path[N];
int pathSize;

inline bool check(int x) {
  int l = 1, r = pathSize;
    while(l <= r) {
      int mid = (l + r) >> 1;
        if(a[mid] == x) return true;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
}

inline int read() {
    int x = 0, f = 1;
      char ch = gc();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = gc();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) { pc('-'); x = -x; }
    if (x > 9) write(x / 10);
    pc(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    pc('\n');
}

inline void writesp(int x) {
    write(x);
    pc(' ');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n = read();
    rep(i, 1, n) a[i] = read();
    int s = read(), t = read();
    
    if (s == t) {
        writeln(1);
        writeln(s);
        return 0;
    }
    
    rep(i, 1, MAX) spf[i] = i;
    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i)
            for (int j = i * i; j <= MAX; j += i)
                if (spf[j] == j) spf[j] = i;
    }
    
    rep(i, 1, n) {
        int x = a[i], last = 0;
        while (x > 1) {
            int p = spf[x];
            if (p != last) {
                primes[i][primeSize[i]++] = p;
                last = p;
            }
            x /= p;
        }
    }
    
    rep(i, 1, n) {
        rep(j, 0, primeSize[i] - 1) {
            int p = primes[i][j];
            primeToSpiders[p][primeToSpidersSize[p]++] = i;
        }
    }
    
    memset(dist, -1, sizeof(dist));
    memset(par, -1, sizeof(par));
    queue<int> q;
    vis[s] = true;
    dist[s] = 0;
    q.push(s);
    
      bool found = false;
    while (!q.empty() && !found) {
        int u = q.front(); q.pop();
        rep(j, 0, primeSize[u] - 1) {
            int p = primes[u][j];
            if (!used[p]) {
                used[p] = true;
                rep(k, 0, primeToSpidersSize[p] - 1) {
                    int v = primeToSpiders[p][k];
                    if (!vis[v]) {
                        vis[v] = true;
                        par[v] = u;
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        if (v == t) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (found) break;
        }
    }
    
    if (!vis[t]) {
        puts("-1");
        return 0;
    }
    
    for (int cur = t; cur != -1; cur = par[cur])
        path[pathSize++] = cur;
    
    per(i, (pathSize - 1) >> 1, 0)
        swap(path[i], path[pathSize - 1 - i]);
    
    writeln(pathSize);
    rep(i, 0, pathSize - 1) writesp(path[i]);
    pc('\n');
    
    return 0;
}