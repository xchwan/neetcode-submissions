class Solution {
    int dfs(int n, int i, unordered_map<int, int>& memo) {
        if (min(n, i) == 0) {
            return 1;
        }

        if (memo.count(n)) {
            return memo[n];
        }

        if (i > n) {
            return dfs(n, n, memo);
        }

        return memo[n] = max(i * dfs(n - i, i, memo), dfs(n, i - 1, memo));
    }
public:
    int integerBreak(int n) {
        unordered_map<int, int> memo;
        return dfs(n, n - 1, memo);
    }
};