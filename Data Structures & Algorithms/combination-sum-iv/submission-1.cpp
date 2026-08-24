class Solution {
    int dfs(vector<int>& nums, int target, vector<int>& memo) {
        if (target == 0) return 1;

        if (memo[target] != -1) return memo[target];

        int res = 0;

        for (int num : nums) {
            if (target - num >= 0) {
                res += dfs(nums, target - num, memo);
            }
        }

        return memo[target] = res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return dfs(nums, target, memo);
    }
};