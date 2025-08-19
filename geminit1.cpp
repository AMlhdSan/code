#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

// 用于构建后缀数组、LCP数组和RMQ(ST表)的结构体
struct SuffixAutomaton {
    int n;
    std::string s;
    std::vector<int> sa, rnk, lcp;
    std::vector<std::vector<int>> st;
    // st.resize(n);

    SuffixAutomaton(const std::string& str) {
        s = str;
        n = s.length();
        sa.resize(n);
        rnk.resize(n);
        lcp.resize(n);
        // lcp.rnk(n);
        build_sa();
        build_lcp();
        build_st();
    }

    void build_sa() {
        std::vector<int> p(n), c(n), cnt(std::max(n, 256));
        for (int i = 0; i < n; ++i) cnt[s[i]]++;
        for (int i = 1; i < 256; ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) sa[--cnt[s[i]]] = i;

        c[sa[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            if (s[sa[i]] != s[sa[i - 1]]) classes++;
            c[sa[i]] = classes - 1;
        }
        p.resize(n);

        for (int h = 1; h < n; h <<= 1) {
            for (int i = 0; i < n; ++i) p[i] = (sa[i] - h + n) % n;
            std::fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; ++i) cnt[c[p[i]]]++;
            for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--cnt[c[p[i]]]] = p[i];
            
            std::vector<int> c_new(n);
            c_new[sa[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; ++i) {
                std::pair<int, int> cur = {c[sa[i]], c[(sa[i] + h) % n]};
                std::pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + h) % n]};
                if (cur != prev) classes++;
                c_new[sa[i]] = classes - 1;
            }
            c = c_new;
        }
        for(int i = 0; i < n; ++i) rnk[sa[i]] = i;
    }

    void build_lcp() {
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (rnk[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[rnk[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rnk[i]] = k;
            if (k) k--;
        }
    }

    void build_st() {
        int log_n = std::log2(n) + 1;
        st.assign(n, std::vector<int>(log_n));
        for (int i = 0; i < n; ++i) st[i][0] = lcp[i];
        for (int j = 1; j < log_n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_lcp(int i, int j) {
        if (i < 0 || i >=n || j < 0 || j >= n || i == j) return n;
        int l = rnk[i], r = rnk[j];
        if (l > r) std::swap(l, r);
        int len = r - l;
        int k = std::log2(len);
        return std::min(st[l][k], st[r - (1 << k)][k]);
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::string a, b, c;
    std::cin >> a >> b >> c;

    // --- 正向LCP ---
    std::string s_fwd = a + '#' + b + '$' + c;
    SuffixAutomaton sa_fwd(s_fwd);
    auto get_lcp = [&](char s1_id, int i, char s2_id, int j) {
        int idx1, idx2;
        if (s1_id == 'a') idx1 = i - 1; else if (s1_id == 'b') idx1 = n + 1 + i - 1; else idx1 = 2 * n + 2 + i - 1;
        if (s2_id == 'a') idx2 = j - 1; else if (s2_id == 'b') idx2 = n + 1 + j - 1; else idx2 = 2 * n + 2 + j - 1;
        return sa_fwd.query_lcp(idx1, idx2);
    };

    // --- 反向LCP (LCSuf) ---
    std::string ra = a, rb = b, rc = c;
    std::reverse(ra.begin(), ra.end());
    std::reverse(rb.begin(), rb.end());
    std::reverse(rc.begin(), rc.end());
    std::string s_rev = ra + '#' + rb + '$' + rc;
    SuffixAutomaton sa_rev(s_rev);
    auto get_lcs = [&](char s1_id, int i, char s2_id, int j) {
        // LCSuf(a_{1..k}) is LCP(ra_{n-k+1..})
        // 0-based index for a_{k} is k-1. In ra, it becomes n-(k-1)-1 = n-k
        int idx1, idx2;
        if (s1_id == 'a') idx1 = n - i; else if (s1_id == 'b') idx1 = n + 1 + (n - i); else idx1 = 2 * n + 2 + (n - i);
        if (s2_id == 'a') idx2 = n - j; else if (s2_id == 'b') idx2 = n + 1 + (n - j); else idx2 = 2 * n + 2 + (n - j);
        return sa_rev.query_lcp(idx1, idx2);
    };

    long long min_ans = 3LL * n;

    for (int k = 1; k < n; ++k) {
        // Case 1: a-b, b-c
        int lcs_ab = get_lcs('a', k, 'b', k);
        int lcp_bc = get_lcp('b', k + 1, 'c', k + 1);
        min_ans = std::min(min_ans, (long long)lcs_ab + lcp_bc + std::min(lcs_ab, lcp_bc));

        // Case 2: b-c, c-a
        int lcs_bc = get_lcs('b', k, 'c', k);
        int lcp_ca = get_lcp('c', k + 1, 'a', k + 1);
        min_ans = std::min(min_ans, (long long)lcs_bc + lcp_ca + std::min(lcs_bc, lcp_ca));
        
        // Case 3: c-a, a-b
        int lcs_ca = get_lcs('c', k, 'a', k);
        int lcp_ab = get_lcp('a', k + 1, 'b', k + 1);
        min_ans = std::min(min_ans, (long long)lcs_ca + lcp_ab + std::min(lcs_ca, lcp_ab));
    }
    std::cout << min_ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}