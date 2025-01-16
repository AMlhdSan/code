#include <bits/stdc++.h>

#define N 500010
#define LOG 20
#define PII pair<int, int>

using namespace std;

int n, k, L, R;
int a[N];
int sum[N];

// ST 表
int st_max[N][LOG]; // 存储区间最大值
int st_idx[N][LOG]; // 存储最大值对应的索引

// 构建 ST 表
void build_st() {
    for (int i = 1; i <= n; ++i) {
        st_max[i][0] = sum[i];
        st_idx[i][0] = i;
    }
    int log_n = log2(n);
    for (int j = 1; j <= log_n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            if (st_max[i][j - 1] >= st_max[i + (1 << (j - 1))][j - 1]) {
                st_max[i][j] = st_max[i][j - 1];
                st_idx[i][j] = st_idx[i][j - 1];
            } else {
                st_max[i][j] = st_max[i + (1 << (j - 1))][j - 1];
                st_idx[i][j] = st_idx[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

// 查询区间最大值和索引
PII query_st(int l, int r) {
    if (l > r) return {INT_MIN, -1}; // 空区间处理
    int len = r - l + 1;
    int log_len = log2(len);
    if (st_max[l][log_len] >= st_max[r - (1 << log_len) + 1][log_len]) {
        return {st_max[l][log_len], st_idx[l][log_len]};
    } else {
        return {st_max[r - (1 << log_len) + 1][log_len], st_idx[r - (1 << log_len) + 1][log_len]};
    }
}

struct node {
    int l, rl, rr, mx;
    bool operator<(const node& y) const {
        return sum[mx] - sum[l - 1] < sum[y.mx] - sum[y.l - 1];
    }
};

priority_queue<node> q;

// 查询区间最大值索引
inline int get_max(int l, int r) {
    return query_st(l, r).second;
}

int main() {
    cin >> n >> k >> L >> R;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    // 构建 ST 表
    build_st();

    for (int i = 1; i <= n; ++i) {
        if (i + L - 1 <= n) {
            node tmp;
            tmp.l = i;
            tmp.rl = i + L - 1;
            tmp.rr = min(i + R - 1, n);
            tmp.mx = get_max(tmp.rl, tmp.rr);
            q.push(tmp);
        }
    }

    long long ans = 0;

    for (int i = 1; i <= k; ++i) {
        if (q.empty()) break; // 防止优先队列为空时出错
        node tmp = q.top();
        q.pop();
        ans += sum[tmp.mx] - sum[tmp.l - 1];
        // 拆分左区间
        if (tmp.rl <= tmp.mx - 1) {
            node tp;
            tp.l = tmp.l;
            tp.rl = tmp.rl;
            tp.rr = tmp.mx - 1;
            tp.mx = get_max(tp.rl, tp.rr);
            if (tp.mx != -1) q.push(tp);
        }
        // 拆分右区间
        if (tmp.mx + 1 <= tmp.rr) {
            node tp;
            tp.l = tmp.l;
            tp.rl = tmp.mx + 1;
            tp.rr = tmp.rr;
            tp.mx = get_max(tp.rl, tp.rr);
            if (tp.mx != -1) q.push(tp);
        }
    }

    cout << ans << endl;

    return 0;
}

// 线段树写法 MLE
/*
#include <bits/stdc++.h>

#define N 500010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define PII pair<int, int>

using namespace std;

int n;
int k, L, R;
int a[N];
int sum[N];

int tree[N << 2];
int maxx[N << 2];

inline void upd(int p) {
    if(tree[ls] > tree[rs]) {
        maxx[p] = maxx[ls];
    }
    else {
        maxx[p] = maxx[rs];
    }
    tree[p] = max(tree[ls], tree[rs]);
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = sum[l];
        maxx[p] = l;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline PII qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return make_pair(tree[p], maxx[p]);
    }
    PII mmm;
    mmm.first = mmm.second = 0;
    if(ql <= mid) {
        PII tp = qry(ls, l, mid, ql, qr);
        mmm = (mmm.first < tp.first ? tp : mmm);
    }
    if(qr > mid) {
        PII tp = qry(rs, mid + 1, r, ql, qr);
        mmm = (mmm.first < tp.first ? tp : mmm);
    }
    return mmm;
}

struct node {
    int l;
    int rl, rr;
    int mx;
    bool operator <(node y) const {
        return sum[mx] - sum[l - 1] < sum[y.mx] - sum[y.l - 1];
    }
};

priority_queue<node> q;

inline int get_max(int l, int r) {
    return qry(1, 1, n, l, r).second;
}

int main() {

    cin >> n;
    cin >> k >> L >> R;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    build(1, 1, n);

    for(int i = 1; i <= n; ++i) {
        if(i + L - 1 <= n) {
            node tmp;
            tmp.l = i;
            tmp.rl = i + L - 1;
            tmp.rr = min(i + R - 1, n);
            tmp.mx = get_max(tmp.rl, tmp.rr);
            q.push(tmp);
        }
    }

    long long ans = 0;

    for(int i = 1; i <= k; ++i) {
        node tmp = q.top();
        q.pop();
        ans += sum[tmp.mx] - sum[tmp.l - 1];
        if(tmp.l != tmp.mx) {
            node tp;
            tp.l = tmp.l;
            tp.rl = tmp.rl;
            tp.rr = tmp.mx - 1;
            tp.mx = get_max(tp.rl, tp.rr);
            q.push(tp);
        }
        if(tmp.mx != tmp.rr) {
            node tp;
            tp.l = tmp.l;
            tp.rl = tmp.mx + 1;
            tp.rr = tmp.rr;
            tp.mx = get_max(tp.rl, tp.rr);
            q.push(tp);
        }
    }

    cout << ans << endl;

    return 0;
}
*/