class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                if (grid[r][c] == 1) {
                    ++fresh;
                }
            }
        }

        int times = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(fresh > 0 && !q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nr = r + dirs[j][0];
                    int nc = c + dirs[j][1];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        --fresh;
                    }
                }
            }
            ++times;
        }

        return (fresh == 0) ? times : -1;
    }
};
