// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

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

const int MAXK = 5005;
int kb;
int xb[MAXK], yb[MAXK], ub[MAXK], vb[MAXK];

string div2quot(string s, int &rem) {
    string q;
    q.reserve(s.size());
    int carry = 0;
    for (char ch : s) {
        int cur = carry * 10 + (ch - '0');
        int d = cur / 2;
        carry = cur % 2;
        if (!q.empty() || d != 0) q.push_back(char('0' + d));
    }
    if (q.empty()) q = "0";
    rem = carry;
    return q;
}

bool decstr_to_bits_limit(string s, int k, int arr[]) {
    for (int i = 0; i < k; ++i) {
        int r;
        s = div2quot(s, r);
        arr[i] = r;
    }
    return s != "0";
}

int main() {
    kb = read();
    string sx, sy;
    if (!(cin >> sx >> sy)) return 0;
    if (kb <= 0) {
        if (sx == "0" && sy == "0") {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return 0;
    }
    bool bigx = decstr_to_bits_limit(sx, kb, xb);
    bool bigy = decstr_to_bits_limit(sy, kb, yb);
    if (bigx || bigy) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < kb; ++i) {
        ub[i] = 1 - xb[i];
        vb[i] = 1 - yb[i];
    }
    cpp_int dp[16], ndp[16];
    for (int i = 0; i < 16; ++i) dp[i] = 0;
    int init = (0<<3) | (0<<2) | (1<<1) | 1;
    dp[init] = 1;
    for (int t = 0; t < kb; ++t) {
        for (int i = 0; i < 16; ++i) ndp[i] = 0;
        for (int s = 0; s < 16; ++s) {
            if (dp[s] == 0) continue;
            int cx = (s >> 3) & 1;
            int cy = (s >> 2) & 1;
            int tu = (s >> 1) & 1;
            int tv = s & 1;
            for (int ubt = 0; ubt <= 1; ++ubt) {
                if (tu && ubt > ub[t]) continue;
                for (int vbt = 0; vbt <= 1; ++vbt) {
                    if (tv && vbt > vb[t]) continue;
                    int sumi = ubt + xb[t] + cx;
                    int ibit = sumi & 1;
                    int ncx = (sumi >> 1);
                    int sumj = vbt + yb[t] + cy;
                    int jbit = sumj & 1;
                    int ncy = (sumj >> 1);
                    if (jbit == 1 && ibit == 0) continue;
                    int ntu = (tu && (ubt == ub[t])) ? 1 : 0;
                    int ntv = (tv && (vbt == vb[t])) ? 1 : 0;
                    int ns = (ncx<<3) | (ncy<<2) | (ntu<<1) | ntv;
                    ndp[ns] += dp[s];
                }
            }
        }
        for (int i = 0; i < 16; ++i) dp[i] = ndp[i];
    }
    cpp_int ans = 0;
    for (int s = 0; s < 16; ++s) {
        int cx = (s >> 3) & 1;
        int cy = (s >> 2) & 1;
        if (cx == 0 && cy == 0) ans += dp[s];
    }
    cout << ans.convert_to<string>() << '\n';
    return 0;
}
