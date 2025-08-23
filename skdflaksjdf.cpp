// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

unordered_map<string,string> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    string ln;
    getline(cin, ln);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        if (s.size() == 0) { --i; continue; }
        istringstream iss(s);
        string lang;
        iss >> lang;
        string w;
        while (iss >> w) {
            for (char &c : w) c = tolower((unsigned char)c);
            mp[w] = lang;
        }
    }
    getline(cin, ln);
    // getline(cin, ln);
    while (getline(cin, ln)) {
        string cur;
        string ans;
        for (char c : ln) {
            if (isalpha((unsigned char)c) || c == '-' || c == '\'' || c == '\\') {
                cur.push_back(c);
            } else {
                if (!cur.empty()) {
                    string t = cur;
                    for (char &cc : t) cc = tolower((unsigned char)cc);
                    auto it = mp.find(t);
                    if (it != mp.end()) { ans = it->second; break; }
                    cur.clear();
                }
            }
        }
        if (ans.empty() && !cur.empty()) {
            string t = cur;
            for (char &cc : t) cc = tolower((unsigned char)cc);
            auto it = mp.find(t);
            if (it != mp.end()) ans = it->second;
        }
        if (!ans.empty()) cout << ans << '\n';
    }
    return 0;
}
