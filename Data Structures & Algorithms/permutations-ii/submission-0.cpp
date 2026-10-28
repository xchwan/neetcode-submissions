class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subvec, vector<bool>& selected) {
        if (subvec.size() == nums.size()) {
            res.push_back(subvec);
            return;
        }

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (selected[i] || (i > 0 && nums[i] == nums[i - 1] && !selected[i - 1])) {
                continue;
            }
            subvec.push_back(nums[i]);
            selected[i] = true;
            dfs(nums, res, subvec, selected);
            subvec.pop_back();
            selected[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subvec;
        int n = nums.size();
        vector<bool> selected(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, res, subvec, selected);
        return res;
    }
};