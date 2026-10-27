class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subvec, vector<bool>& used) {
        int n = nums.size();

        if (subvec.size() == nums.size()) {
            res.push_back(subvec);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            subvec.push_back(nums[i]);
            used[i] = true;
            dfs(nums, res, subvec, used);
            subvec.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> subvec;
        vector<bool> used(n, false);

        dfs(nums, res, subvec, used);

        return res;
    }
};
