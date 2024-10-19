#include <iostream>
#include <vector>

using namespace std;

int maxDifferentNumbers(vector<int> nums) {
    int maxBit = 0;
    for (int num : nums) {
        maxBit = max(maxBit, (int)log2(num) + 1);
    }

    vector<vector<bool> > dp(maxBit + 1, vector<bool>(1 << maxBit));
    dp[0][0] = true;

    for (int i = 1; i <= maxBit; ++i) {
        for (int num : nums) {
            for (int j = 0; j < (1 << maxBit); ++j) {
                dp[i][j] |= dp[i - 1][j] || dp[i - 1][j ^ (1 << (i - 1))];
            }
        }
    }

    return count(dp[maxBit].begin(), dp[maxBit].end(), true);
}

int main() {
    vector<int> nums = {0, 1, 3, 5};
    int result = maxDifferentNumbers(nums);
    cout << result << endl;
    return 0;
}