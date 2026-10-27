class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subvec, int idx) {
        int n = nums.size();
        res.push_back(subvec);

        if (idx == n) return;

        for (int i = idx; i < n; ++i) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            subvec.push_back(nums[i]);
            dfs(nums, res, subvec, i + 1);
            subvec.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subvec;
        sort(nums.begin(), nums.end());
        dfs(nums, res, subvec, 0);
        return res;
    }
};
