class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid) {
        if (grid[i][j] == '0' || grid[i][j] == '#') return;
        grid[i][j] = '#';
        static const vector<int> dx{-1, 1, 0, 0};
        static const vector<int> dy{0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int cx = i + dx[k];
            int cy = j + dy[k];
            if (cy >= 0 && cx >= 0 && cx < grid.size() && cy < grid[0].size()) {
                // then let's recurse
                dfs(cx, cy, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++islandCnt;
                    // now we need to make this island all negative 1 so we don't count it again
                    dfs(i, j, grid);
                }
                // in the other case this is either not an island or we have already visited
            }
        }
        return islandCnt;
    }
};