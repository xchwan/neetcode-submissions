class Solution {
    bool isParentheses(string parenthese) {
        stack<char> stk;
        for (char c : parenthese) {
            if (c == '(') {
                stk.push(c);
            } else if (!stk.empty() && c == ')'){
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }

    void dfs(vector<string>& res, string& parenthese, string& subres, vector<bool>& selected) {
        if (subres.size() == parenthese.size()&& isParentheses(subres)) {
            res.push_back(subres);
            return;
        }

        int n = parenthese.size();

        for (int i = 0; i < n; ++i) {
            if (selected[i] || (i > 0 && parenthese[i] == parenthese[i - 1] && !selected[i - 1])){
                continue;
            }

            subres += parenthese[i];
            selected[i] = true;
            dfs(res, parenthese, subres, selected);
            subres.pop_back();
            selected[i] = false;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string parenthese;
        string subres;

        for (int i = 0; i < n; ++i) {
            parenthese += '(';
            parenthese += ')';
        }

        sort(parenthese.begin(), parenthese.end());

        vector<bool> selected(2 * n, false);
        dfs(res, parenthese, subres, selected);
        return res;
    }
};
