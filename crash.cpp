// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include<bits/stdc++.h>
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

int to_[100005], a[100005], b[100005], c[100005], x1_[100005], c1[100005], d1[100005], x2[100005], c2[100005], d2[100005];

inline int rmod(int x, int mod) {
    return x - mod + ((x - mod >> 31) & mod);
}

inline int lmod(int x, int mod) {
    return x + ((x >> 31) & mod);
}

int main() {

    freopen("crash.in", "r", stdin);
    freopen("crash.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin.cout.tie(0);

    int n = read(), l = read(), t = read();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        x1_[i] = read();
        c1[i] = read();
        d1[i] = read();
        a[i] = x1_[i];
        if (d1[i] >= 0) b[cnt1++] = x1_[i];
        else c[cnt2++] = x1_[i];
    }
    sort(a, a + n);
    sort(b, b + cnt1);
    sort(c, c + cnt2);
    for (int i = 0; i < n; i++) to_[lower_bound(a, a + n, x1_[i]) - a] = i;
    t <<= 1;
    int x = t / l, y = t % l;
    t >>= 1;
    for (int i = 0; i < n; i++) {
        if (d1[i] >= 0) {
            int pos = (int)(lower_bound(a, a + n, x1_[i]) - a) + x * cnt2;
            if (y + x1_[i] < l) pos += (int)(upper_bound(c, c + cnt2, y + x1_[i]) - lower_bound(c, c + cnt2, x1_[i]));
            else pos += cnt2 + (int)(upper_bound(c, c + cnt2, y + x1_[i] - l) - lower_bound(c, c + cnt2, x1_[i]));
            pos = to_[pos % n];
            x2[pos] = (x1_[i] + t) % l;
            c2[pos] = c1[i];
            d2[pos] = 1;
        } else {
            int tmp = (int)(lower_bound(a, a + n, x1_[i]) - a);
            int pos = tmp - x * cnt1;
            if (x1_[i] - y < 0) pos -= cnt1 + (int)(upper_bound(b, b + cnt1, x1_[i]) - lower_bound(b, b + cnt1, x1_[i] - y + l));
            else pos -= (int)(upper_bound(b, b + cnt1, x1_[i]) - lower_bound(b, b + cnt1, x1_[i] - y));
            if (pos != tmp) {
                int diff = tmp - pos;
                int p = lmod(((int)(lower_bound(b, b + cnt1, x1_[i]) - b) - diff) % cnt1, cnt1);
                pos = to_[lmod(pos % n, n)];
                c2[pos] = c1[to_[lower_bound(a, a + n, b[p]) - a]];
            } else {
                pos = to_[lmod(pos % n, n)];
                c2[pos] = c1[i];
            }
            x2[pos] = lmod((x1_[i] - t) % l, l);
            d2[pos] = -1;
            pos = to_[lmod(pos % n, n)];
        }
    }
    for (int i = 0; i < n; i++) {
        write(x2[i]);
        putchar(' ');
        write(c2[i]);
        putchar(' ');
        write(d2[i]);
        putchar('\n');
    }
    return 0;
}
