class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        constexpr int dx[4] = {-1, 1, 0, 0};
        constexpr int dy[4] = {0, 0, 1, -1};
        // let's do BFS
        queue<pair<int, int>> just_rotten;
        int minutes = 0;
        // go through and add them all to the queue
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    just_rotten.push({i, j});
                }
            }
        }
        while (true) {
            int size = just_rotten.size();
            for (int i = 0; i < size; ++i) {
                auto curr_pair = just_rotten.front();
                int cx = curr_pair.first;
                int cy = curr_pair.second;
                // look at the 4 around them and add them if they are also rotten, add them
                for (int i = 0; i < 4; ++i) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() &&
                        grid[nx][ny] == 1) {
                        // let's turn this orange rotten and then add it to our queue
                        grid[nx][ny] = 2; // rotten now
                        just_rotten.push({nx, ny});
                    }
                }
                // we should pop this value off
                just_rotten.pop();
            }
            if (just_rotten.size() == 0) {
                // we added none and went through them all
                break;
            } else {
                ++minutes;
            }
        }
        // scan again if we see a fresh one then that means not possible
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};