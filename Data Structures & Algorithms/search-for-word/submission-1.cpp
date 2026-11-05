class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int wordSize = word.size();
        int m = board.size();
        int n = board[0].size();

        if (k == wordSize) {
            return true;
        }

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k] || board[i][j] == '*') {
            return false;
        }
        char tmp = board[i][j];
        board[i][j] = '*';

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        bool res = false;

        for (auto [r, c] : dirs) {
            if (dfs(board, word, i + r, j + c, k + 1)) {
                return true;
            }
        }
        board[i][j] = tmp;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
