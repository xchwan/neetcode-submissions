class Solution {
    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix, vector<vector<int>>& dirs, vector<vector<int>>& memo) {
        int m = matrix.size(), n = matrix[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= prevVal) {
            return 0;
        }

        if (memo[r][c] != -1) {
            return memo[r][c];
        }

        int res = 1;

        for (vector<int> d : dirs) {
            res = max(res, 1 + dfs(r + d[0], c + d[1], matrix[r][c], matrix, dirs, memo));
        }
        return memo[r][c] = res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> memo(m, vector<int>(n, -1));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                res = max(res, dfs(r, c, INT_MIN, matrix, dirs, memo));
            }
        }
        return res;
    }
};
