class Solution {
    void bfs(vector<vector<char>>& grid, int r, int c, vector<vector<int>>& dirs) {
        queue<pair<int, int>> que;
        grid[r][c] = '0';
        que.push({r, c});

        while(!que.empty()) {
            pair<int, int> node = que.front();
            que.pop();

            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; ++i) {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc <grid[0].size() && grid[nr][nc] == '1') {
                    que.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c, dirs);
                    ++islands;
                }
            }
        }

        return islands;
    }
};
