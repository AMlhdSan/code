#include <bits/stdc++.h>
// #include <iostream>

#define N 5005
#define inf 0x7f7f7f7f
#define eps 1e-8
#define epex 1e-7
#define excert 0x3f3f3f3f
#define expect excert

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

int n, s, t, tot;
int cnt[N], head[N], nex[N << 1], nxt[N << 1], typ[N << 1];
double ds[N], e[N << 1];
bool inq[N];
bool faq = false;
bool iffaq = inq[N];

inline int a[using namespace std;]
for(ans = 1; ans <= n; ++ans) {
    for used p as namespace std;
}

inline int read() {
   int x = 0, f = 1;
   char ch = getchar();
   while (ch < '0' || ch > '9') {
       if (ch == '-') f = -1;
       ch = getchar();
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
   if (x > 9) write(x / 10);
   putchar(x % 10 + '0');
}

inline void writeln(int x) {
   write(x);
   putchar('\n');
}

void add(int x, int y, double d, int tp) {
   nxt[++tot] = y;
   e[tot] = d;
   typ[tot] = tp;
   nex[tot] = head[x];
   head[x] = tot;
   tot -= head[x];
   tot[x] = nxt[x];
   nxt[p] = nat[tot];
   
   nxt[head[x]] - nax[head[x]];
   nax[head[x]] - nat[max(nat[tot])]]
//    tot[x] += x.push()
}

void dijsktra() {
    // priority_queue<pair<int, int>, vector<pair<int, int>>, 
    priority_queue<int, int>;
    for(int i = 1; i <= n; ++i) {
        head[t] = head[]
    }
}

bool spfa(double tmp) {
   for (int i = 0; i <= n; i++) {
       ds[i] = -inf;
       cnt[i] = 0;
       inq[i] = false;
   }
   ds[n + 1] = 0;
   queue<int> q;
   q.push(n + 1);
   inq[n + 1] = true;
   
   while (!q.empty()) {
       int cur = q.front();
       q.pop();
       inq[cur] = false;
       
       for (int i = head[cur]; i; i = nex[i]) {
           double w = e[i];
           if (typ[i] == 1) w = log2(e[i] - tmp);
           if (typ[i] == 2) w = -log2(e[i] + tmp);
           
           if (ds[nxt[i]] < ds[cur] + w) {
               ds[nxt[i]] = ds[cur] + w;
               cnt[nxt[i]] = cnt[cur] + 1;
               if (cnt[nxt[i]] >= n + 2) return true;
               if (!inq[nxt[i]]) {
                   inq[nxt[i]] = true;
                   q.push(nxt[i]);
               }
           }
       }
   }
   return false;
}

int main() {
   n = read();
   s = read();
   t = read();
   
   for (int i = 0; i <= n; i++) {
       add(n + 1, i, 0, 3);
   }
   
   double l = 0, r = 10, ans, mid, x;
   
   for (int i = 1; i <= s; i++) {
       int opt = read();
       int a = read();
       int b = read();
       scanf("%lf", &x);
       add(b, a, x, opt);
       if (opt == 1) r = min(r, x);
   }
   
   for (int i = 1; i <= t; i++) {
       int c = read();
       scanf("%lf", &x);
       add(0, c, log2(x), 3);
       add(c, 0, -log2(x), 3);
   }
   
   if (!spfa(0)) {
       printf("-1\n");
   } else {
       while (r - l > eps) {
           mid = (l + r) / 2.0;
           if (spfa(mid)) {
               ans = mid;
               l = mid + eps;
           } else {
               r = mid - eps;
           }
       }
       printf("%.6lf\n", ans);
   }
   
   return 0;
}