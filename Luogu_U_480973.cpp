#include <bits/stdc++.h>

using namespace std;

int solve(const string &expr, int x, int l, int r) {
    int num = 0;
    bool flag = true;
    for (int i = l; i <= r; ++i) {
        if (!isdigit(expr[i])) {
            flag = false;
            break;
        }
        num = num * 10 + (expr[i] - '0');
    }
    if (flag) {
        return num;
    }

    int qp = -1, cp = -1;
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        if (expr[i] == '?') {
            if (cnt == 0) {
                qp = i;
            }
            ++cnt;
        } else if (expr[i] == ':') {
            --cnt;
            if (cnt == 0) {
                cp = i;
                break;
            }
        }
    }

    string str = expr.substr(l, qp - l);
    bool ans = false;
    if (str[1] == '>') {
        int a = stoi(str.substr(2));
        ans = (x > a);
    } else if (str[1] == '<') {
        int a = stoi(str.substr(2));
        ans = (x < a);
    }

    if (ans) {
        return solve(expr, x, qp + 1, cp - 1);
    } else {
        return solve(expr, x, cp + 1, r);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, q;
    cin >> m >> q;
    string s;
    cin >> s;

    while(q--) {
        int x;
        cin >> x;
        int res = solve(s, x, 0, s.size() - 1);
        cout << res << endl;
    }

    return 0;
}
