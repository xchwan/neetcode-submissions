class Solution {
    void dfs(vector<int>& nums, int sum, int start, int target, vector<vector<int>>& res, vector<int>& subset) {
        if (sum == target) {
            res.push_back(subset);
            return;
        }

        if (sum > target) {
            return;
        }

        int n = nums.size();

        for (int i = start; i < n; ++i) {
            subset.push_back(nums[i]);
            dfs(nums, sum + nums[i], i, target, res, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, 0, target, res, subset);
        return res;
    }
};
