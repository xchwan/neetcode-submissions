class Solution {
    int dfs(vector<int>& nums, int i, unordered_map<int, int>& memo) {       
        int n = nums.size();
        if (memo.count(i)) {
            return memo[i];
        }

        int res = 1;
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] < nums[j]) {
                res = max(res, 1 + dfs(nums, j, memo));
            }
        }

        return memo[i] = res;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int, int> memo;
        
        int maxLIS = 1;
        for (int i = 0; i < nums.size(); ++i) {
            maxLIS = max(maxLIS, dfs(nums, i, memo));
        }
        return maxLIS;
    }
};
