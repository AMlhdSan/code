#include <bits/stdc++.h>

#define N 25

using namespace std;

int n, now, x[3], y[3], x1[N], yy[N];
char a[N][N];
double ans1, ans2;

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

int main() {
   n = read();
   
   for(int i = 1; i <= n; ++i) {
       scanf("%s", a[i]);
       for(int j = 0; j < n; ++j) {
           if(a[i][j] == '1') {
               if(x1[i]) y[0] = i;
               if(yy[j]) x[0] = j;
               x1[i]++;
               yy[j]++;
           }
       }
   }
   
   for(int i = 1; i <= n; ++i) {
       for(int j = 0; j < n; ++j) {
           if(a[i][j] == 'x') {
               y[++now] = y[0] - i;
               x[now] = j - x[0];
           }
       }
   }
   
   if(x1[y[0]] == 1) {
       printf("y=%.4lf", ans2);
       return 0;
   }
   
   if(yy[x[0]] == 1) {
       printf("x=%.4lf", ans1);
       return 0;
   }
   
   if(x[1] == x[2]) {
       printf("x=%.4lf", (double)x[1]);
       return 0;
   }
   
   ans1 = 1.0 * (y[1] - y[2]) / (x[1] - x[2]);
   ans2 = (double)y[1] - ans1 * x[1];
   
   if(ans1 == 0) {
       printf("y=%.4lf", ans2);
   } else {
       printf("y=%.4lfx", ans1);
       if(ans2 == 0) return 0;
       if(ans2 > 0) printf("+");
       printf("%.4lf", ans2);
   }
   
   return 0;
}