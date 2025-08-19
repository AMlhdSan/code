#include <bits/stdc++.h>

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

int getLCP(const string& s1, int st1, const string& s2, int st2) {
    int len = 0;
    int n1 = s1.length(), n2 = s2.length();
    while (st1 + len < n1 && st2 + len < n2 && s1[st1 + len] == s2[st2 + len]) {
        len++;
    }
    return len;
}

int main() {
    int T = read();
    
    while (T--) {
        int n = read();
        string a, b, c;
        cin >> a >> b >> c;
        
        int ans = n;
        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int lcp1 = getLCP(a, 0, b, i);
                lcp1 = min(lcp1, i);
                lcp1 = min(lcp1, j - i);
                
                int lcp2 = getLCP(b, i, c, j);
                lcp2 = min(lcp2, j - i);
                lcp2 = min(lcp2, n - j);
                
                int lcp3 = getLCP(a, 0, c, j);
                lcp3 = min(lcp3, i);
                lcp3 = min(lcp3, n - j);
                
                ans = min(ans, lcp1 + lcp2 + lcp3);
            }
        }
        
        writeln(ans);
    }
    
    return 0;
}