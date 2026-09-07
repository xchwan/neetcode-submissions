class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, 0));
        vector<int> sum_i(n + 1, 0);

        for (int i = n - 1; i >= 0; --i){
            sum_i[i] = sum_i[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= 2 * n; ++m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    dp[i][m] = max(dp[i][m], sum_i[i] - dp[i + x][max(x, m)]);
                }
            }
        }

        return dp[0][1];
    }
};