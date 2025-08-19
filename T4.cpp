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

int main() {
    // int n = read();
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
    }
    
    unordered_map<int, int> bal;
    int add = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal[a[i]]++;
        } else {
            if (bal[a[i]] > 0) {
                bal[a[i]]--;
            } else {
                add++;
            }
        }
    }
    
    for (auto& p : bal) {
        add += p.second;
    }
    
    writeln(add);
    
    return 0;
}