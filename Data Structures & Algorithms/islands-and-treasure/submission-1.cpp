class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
