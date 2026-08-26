class Solution {
    int dfs(int i, vector<int>& stoneValue, vector<int>& dp) {
        int n = stoneValue.size();
        if (i >= n) return 0;
        if (dp[i] != INT_MIN) return dp[i];

        int res = INT_MIN, total = 0;

        for (int j = i; j < min(i + 3, n); ++j) {
            total += stoneValue[j];
            res = max(res, total - dfs(j + 1, stoneValue, dp));
        }

        return dp[i] = res;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int res = dfs(0, stoneValue, dp);
        if (res == 0) return "Tie";
        return (res > 0) ? "Alice" : "Bob";
    }
};