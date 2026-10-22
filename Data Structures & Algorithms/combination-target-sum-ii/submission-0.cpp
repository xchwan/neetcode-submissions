class Solution {
    void dfs(vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int>& subset) {
        int n = candidates.size();
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = idx; i < n; ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            subset.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, res, subset);
            subset.pop_back();
        }        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, res, subset);
        return res;
    }
};
