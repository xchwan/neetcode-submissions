class Solution {
    bool dfs(vector<int>& nums, int target, int i, vector<vector<int>>& memo) {
        if (i == nums.size()) return target == 0;
        if (target < 0) return false;

        if (memo[i][target] != -1) return memo[i][target];

        return memo[i][target] = dfs(nums, target - nums[i], i + 1, memo) || dfs(nums, target, i + 1, memo);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;

        vector<vector<int>> memo(nums.size(), vector<int>(sum / 2 + 1, -1));

        return dfs(nums, sum / 2, 0, memo);
    }
};
