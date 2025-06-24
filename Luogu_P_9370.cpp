#include <bits/stdc++.h>

double solve(int N, int M, int K, int H, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    const double INF = std::numeric_limits<double>::infinity();
    std::vector<std::vector<std::pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        adj[x[i]].push_back({y[i], c[i]});
        adj[y[i]].push_back({x[i], c[i]});
    }

    int k_cap = std::min(K, 70);

    std::vector<std::vector<double>> dist(N, std::vector<double>(k_cap + 1, INF));

    std::priority_queue<std::tuple<double, int, int>> pq;

    dist[0][0] = 0.0;
    pq.push({-0.0, 0, 0});

    while (!pq.empty()) {
        auto [d_neg, u, k] = pq.top();
        pq.pop();

        double d = -d_neg;

        if (d > dist[u][k] + 1e-9) { 
            continue;
        }
        
        if (u == H) {
            continue;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            double t = d + w;

            if (arr[v] == 0) {
                if (0.0 < dist[v][k]) {
                    dist[v][k] = 0.0;
                    pq.push({-0.0, v, k});
                }
            } 
            else if (arr[v] == 1) { 
                if (t < dist[v][k]) {
                    dist[v][k] = t;
                    pq.push({-t, v, k});
                }
            } 
            else { 
                if (t < dist[v][k]) {
                    dist[v][k] = t;
                    pq.push({-t, v, k});
                }
                
                if (k + 1 <= k_cap) {
                    double t_div = t / 2.0;
                    if (t_div < dist[v][k + 1]) {
                        dist[v][k + 1] = t_div;
                        pq.push({-t_div, v, k + 1});
                    }
                }
            }
        }
    }

    double ans = INF;
    for (int i = 0; i <= k_cap; ++i) {
        ans = std::min(ans, dist[H][i]);
    }

    if (std::isinf(ans)) {
        return -1.0;
    } else {
        return ans;
    }
}