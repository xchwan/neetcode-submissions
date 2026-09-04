class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (abs(target) > sum) return 0;

        int n = 2 * sum + 1;

        vector<vector<int>> dp(m + 1, vector<int>(n, 0));

        dp[m][sum] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (j + nums[i] < n) dp[i][j + nums[i]] += dp[i + 1][j];
                if (j - nums[i] >= 0) dp[i][j - nums[i]] += dp[i + 1][j];
            }
        }

        return dp[0][target + sum];
    }
};
