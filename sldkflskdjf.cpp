#include <iostream>
#include <vector>
#include <numeric>

// Function for fast I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Define constants
const int MOD = 998244353;
const int V = 524288; // 2^19, as max a_i is 5*10^5

// The function that solves a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    // The DP table. std::vector allocates on the heap, avoiding stack overflow.
    std::vector<int> dp(V, 0);
    
    for (int v : a) {
        // Use a vector of pairs to store updates for the current step.
        // This is generally more performant than std::map for this use case.
        std::vector<std::pair<int, int>> updates;
        
        // Rule 2: Extend existing subsequences by appending 'v'
        // Iterate through all multiples of 'v'
        for (int x = 0; x < V; x += v) {
            if (dp[x] > 0) {
                // If a valid subsequence with XOR sum 'x' exists,
                // we can create 'dp[x]' new subsequences with XOR sum 'x ^ v'.
                updates.push_back({x ^ v, dp[x]});
            }
        }
        
        // Rule 1: Start a new subsequence with just 'v'
        updates.push_back({v, 1});
        
        // Apply all the collected updates to the DP table
        for (const auto& p : updates) {
            int y = p.first;
            int count = p.second;
            // Use long long for the intermediate addition to prevent overflow
            dp[y] = (static_cast<long long>(dp[y]) + count) % MOD;
        }
    }
    
    // Calculate the total number of valid subsequences by summing up the dp table
    long long total_count = 0;
    for (int count : dp) {
        total_count = (total_count + count) % MOD;
    }
    
    std::cout << total_count << "\n";
}

int main() {
    fast_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}