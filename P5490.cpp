#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;

int n;
ll area = 0;
struct Event {
    int x, y1, y2, flag;
    bool operator<(const Event& e) const {
        return x < e.x;
    }
} events[N << 1];

ll tree[N << 2];
int cnt[N << 2];
vector<int> ys;

void push_up(int p, int l, int r) {
    if (cnt[p] > 0) {
        tree[p] = ys[r + 1] - ys[l];
    } else {
        if (l == r) tree[p] = 0;
        else tree[p] = tree[ls] + tree[rs];
    }
}

void update(int p, int l, int r, int ql, int qr, int flag) {
    if (ql <= l && r <= qr) {
        cnt[p] += flag;
        push_up(p, l, r);
        return;
    }

    int mid = (l + r) >> 1;

    if (ql <= mid) 
        update(ls, l, mid, ql, qr, flag);
    if (qr > mid) 
        update(rs, mid + 1, r, ql, qr, flag);
    
    push_up(p, l, r);
}

int main() {
    cin >> n;
    int x1, y1, x2, y2;
    
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        Event tmp1;
        tmp1.x = x1, tmp1.y1 = y1, tmp1.y2 = y2, tmp1.flag = 1;
        Event tmp2;
        tmp2.x = x2, tmp2.y1 = y1, tmp2.y2 = y2, tmp2.flag = -1;
        events[i * 2 - 1] = tmp1;
        events[i * 2] = tmp2;
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());

    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    sort(events + 1, events + 2 * n + 1);

    for (int i = 1; i < 2 * n; ++i) {
        int x = events[i].x;
        int y1 = lower_bound(ys.begin(), ys.end(), events[i].y1) - ys.begin() + 1;
        int y2 = lower_bound(ys.begin(), ys.end(), events[i].y2) - ys.begin();
        
        update(1, 1, ys.size() - 1, y1, y2, events[i].flag);
        
        area += (ll)(events[i + 1].x - x) * tree[1];
    }

    cout << area << endl;
    return 0;
}
