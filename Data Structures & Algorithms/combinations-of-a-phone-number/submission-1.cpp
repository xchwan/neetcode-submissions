class Solution {
    void dfs(string& digits, vector<string>& res, string& sub, unordered_map<char, string>& mp, int i) {
        int n = digits.size();
        if (i == n && !sub.empty()) {
            res.push_back(sub);
            return;
        }

        for (char c : mp[digits[i]]) {
            sub.push_back(c);
            dfs(digits, res, sub, mp, i + 1);
            sub.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string sub;
        unordered_map<char, string> mp;

        mp[2 + '0'] = "abc";
        mp[3 + '0'] = "def";
        mp[4 + '0'] = "ghi";
        mp[5 + '0'] = "jkl";
        mp[6 + '0'] = "mno";
        mp[7 + '0'] = "pqrs";
        mp[8 + '0'] = "tuv";
        mp[9 + '0'] = "wxyz";

        dfs(digits, res, sub, mp, 0);

        return res;
    }
};
