class Solution {
    bool isPalindrome(string& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(string& s, vector<vector<string>>& res, vector<string>& subVec, int i) {
        int n = s.size();
        if (i == n) {
            res.push_back(subVec);
            return;
        }

        for (int j = i; j < n; ++j) {
            string subString = s.substr(i, j - i + 1);
            if (isPalindrome(subString)) {
                subVec.push_back(subString);
                dfs(s, res, subVec, j + 1);
                subVec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subVec;
        dfs(s, res, subVec, 0);
        return res;      
    }
};
