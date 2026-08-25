class Solution {
    int dfs(int n, vector<int>& memo) {
        if (n == 0) return 0;
        if (memo[n] != -1) return memo[n];

        int res = INT_MAX;

        for (int i = 1; i * i <= n; ++i) {
            if (n - (i * i) >= 0) {
                res = min(res, 1 + dfs(n - (i * i), memo));
            }
        }

        return memo[n] = res;
    }
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }
};