class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> hasEdge(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') {
                q.push({r, 0});
                hasEdge[r][0] = true;
            }
            if (board[r][n - 1] == 'O') {
                q.push({r, n - 1});
                hasEdge[r][n - 1] = true;
            }
        }

        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') {
                q.push({0, c});
                hasEdge[0][c] = true;
            }
            if (board[m - 1][c] == 'O') {
                q.push({m - 1, c});
                hasEdge[m - 1][c] = true;
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && !hasEdge[nr][nc] && board[nr][nc] == 'O') {
                    hasEdge[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!hasEdge[r][c] && board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
