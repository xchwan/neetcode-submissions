class Solution {
    void dfs(vector<int>& nums, int k, int idx, vector<vector<int>>& res, vector<int>& subset) {
        int m = subset.size();
        int n = nums.size();
        if (m == k) {
            res.push_back(subset);
            return;
        }

        for (int i = idx; i <= n - (k - m); ++i) {
            subset.push_back(nums[i]);
            dfs(nums, k, i + 1, res, subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;

        vector<int> nums(n, 0);

        for (int i = 1; i <= n; ++i) {
            nums[i - 1] = i;
        }

        dfs(nums, k, 0, res, subset);
        return res;
    }
};