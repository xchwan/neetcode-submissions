class Solution {
    void bfs(vector<vector<int>>& grid, int r, int c, int& maxArea, vector<vector<int>>& dirs) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        int area = 0;

        while(!q.empty()) {
            pair<int, int> node = q.front();
            ++area;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = node.first + dirs[i][0];
                int nc = node.second + dirs[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }

        maxArea = max(maxArea, area);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    bfs(grid, r, c, maxArea, dirs);
                }
            }
        }

        return maxArea;
    }
};
