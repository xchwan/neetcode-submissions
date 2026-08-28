class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;

        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }

        int target = sum / 2;
        int n = stones.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j]; 
                if (j - stones[i - 1] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i - 1]];
                }
            }
        }

        int closesum = 0;
        for (int j = target; j >= 0; --j) {
            if (dp[n][j]) {
                closesum = j;
                break;
            }
        }

        return sum - 2 * closesum;
    }
};