class Solution {
    bool dfs(string& s, vector<string>& wordDict, int i, unordered_map<int, bool>& memo) {
        if (memo.count(i)) {
            return memo[i];
        }

        for (const string& w : wordDict) {
            if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
                if (dfs(s, wordDict, i + w.size(), memo)) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo; //s[i:] = true/false
        memo[s.size()] = true;
        return dfs(s, wordDict, 0, memo);
    }
};
