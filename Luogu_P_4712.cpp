#include <bits/stdc++.h>

#define N 100005
#define eps 1e-9

using namespace std;

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

int n;
double a[N];
int r[N];
double f[N];

int main() {
    n = read();
    a[0] = read();
    
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        r[i] = read();
    }
    
    f[0] = a[0];
    
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        
        double sum = 0;
        for (int j = 0; j <= r[i]; j++) {
            sum += f[j];
        }
        
        if (sum * 0.2 < a[i] - eps) {
            printf("-1\n");
            return 0;
        }
        
        if (sum * 0.2 > a[i] + eps) {
            double ratio = a[i] / (sum * 0.2);
            for (int j = 0; j <= r[i]; j++) {
                f[j] *= ratio;
            }
            f[i] = a[i];
            
            for (int j = i + 1; j <= n; j++) {
                double new_sum = 0;
                for (int k = 0; k <= r[j]; k++) {
                    new_sum += f[k];
                }
                if (new_sum * 0.2 < a[j] - eps) {
                    double need_ratio = a[j] / (new_sum * 0.2);
                    for (int k = 0; k <= r[j]; k++) {
                        f[k] *= need_ratio;
                    }
                }
            }
        }
    }
    
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += f[i];
    }

    ans *= 0.2;
    ans -= 1;
    if(ans <= 0) {
        printf("-1");
    }
    
    else printf("%.10f\n", ans * 0.2);
    
    return 0;
}