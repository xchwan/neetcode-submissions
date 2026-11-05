class Solution {
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& visited) {
        int wordSize = word.size();
        int m = board.size();
        int n = board[0].size();

        if (k == wordSize) {
            return true;
        }

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k] || visited[i][j]) {
            return false;
        }

        visited[i][j] = true;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        bool res = false;

        for (auto [r, c] : dirs) {
            res = res || dfs(board, word, i + r, j + c, k + 1, visited);
        }
        visited[i][j] = false;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
