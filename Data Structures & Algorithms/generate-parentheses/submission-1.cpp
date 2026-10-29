class Solution {
    void dfs(vector<string>& res, string& subres, int open, int close, int n) {
        if (subres.size() == 2 * n) {
            res.push_back(subres);
            return;
        }

        if (open < n) {
            subres.push_back('(');
            dfs(res, subres, open + 1, close, n);
            subres.pop_back();
        }

        if (close < open) {
            subres.push_back(')');
            dfs(res, subres, open, close + 1, n);
            subres.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string subres;
        dfs(res, subres, 0, 0, n);
        return res;
    }
};
