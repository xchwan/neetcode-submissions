class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int r = 0; r <= m; ++r) {
            dp[r][n] = m - r;
        }

        for (int c = 0; c <= n; ++c) {
            dp[m][c] = n - c;
        }

        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (word1[r] == word2[c]) {
                    dp[r][c] = dp[r + 1][c + 1];
                } else {
                    dp[r][c] = 1 + min({dp[r + 1][c], dp[r][c + 1], dp[r + 1][c + 1]});
                }
            }
        }

        return dp[0][0];
    }
};
