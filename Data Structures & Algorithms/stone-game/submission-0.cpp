class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        for (int l = n - 2; l >= 0; --l) {
            for (int r = l + 1; r < n; ++r) {
                dp[l][r] = max(piles[l] - dp[l + 1][r], piles[r] - dp[l][r - 1]);
            }
        }

        return (dp[0][n - 1] > 0);
    }
};