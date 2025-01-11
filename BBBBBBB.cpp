#include <bits/stdc++.h>

using namespace std;

int dfs(int a, int b) {
    queue<pair<int, int>> q;
    unordered_set<long long> vis;

    q.push({a, b});
    vis.insert(((long long)a << 32) | b);

    int tt = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [curA, curB] = q.front();
            q.pop();

            if (curA == curB) return tt;

            if (curA <= 1e9) {
                long long noww = ((long long)(curA * 2) << 32) | curB;
                if (!vis.count(noww)) {
                    q.push({curA * 2, curB});
                    vis.insert(noww);
                }
            }

            if (curB > 1) {
                long long noww = ((long long)curA << 32) | (curB - 1);
                if (!vis.count(noww)) {
                    q.push({curA, curB - 1});
                    vis.insert(noww);
                }
            }


            if (curB <= 1e9) {
                long long noww = ((long long)curA << 32) | (curB + 1);
                if (!vis.count(noww)) {
                    q.push({curA, curB + 1});
                    vis.insert(noww);
                }
            }
        }
        tt++;
    }
    return -1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << dfs(a, b) << endl;
    return 0;
}
