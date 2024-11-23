#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1000000;

int n, m;
int arr[MAXN + 1];
int answer[MAXN];

struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_a = (l - 1) / sqrt(n), block_b = (other.l - 1) / sqrt(n);
        if (block_a != block_b)
            return block_a < block_b;
        return r < other.r;
    }
};

unordered_map<int, int> freq;
int max_freq = 0;

void add(int pos) {
    freq[arr[pos]]++;
    if (freq[arr[pos]] > max_freq)
        max_freq = freq[arr[pos]];
}

void remove(int pos) {
    freq[arr[pos]]--;
    if(freq[arr[pos]] == 0)
        freq.erase(arr[pos]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // 转换为0基索引
        queries[i].r--;
        if (queries[i].l > queries[i].r)
            swap(queries[i].l, queries[i].r);
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int L = 0, R = -1;

    for (Query& query : queries) {
        int l = query.l, r = query.r, idx = query.idx;

        while (R < r)
            add(++R);
        while (R > r)
            remove(R--);
        while (L < l)
            remove(L++);
        while (L > l)
            add(--L);

        answer[idx] = r - l + r - l + 1 - max_freq;
    }

    for (int i = 0; i < m; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}