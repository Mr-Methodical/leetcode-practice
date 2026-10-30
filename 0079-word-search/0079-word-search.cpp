class Solution {
    // we can just run dfs on this
    bool dfs(int i, int j, vector<vector<char>> &board, const string &word, int idx) {
        if (word[idx] != board[i][j]) return false;
        if (idx == word.size() - 1) {
            // we got to the last idx and they were all right
            return true;
        }
        static constexpr int dx[4] = {-1, 1, 0, 0};
        static constexpr int dy[4] = {0, 0, -1, 1};
        for (int d = 0; d < 4; ++d) {
            int cx = dx[d] + i;
            int cy = dy[d] + j;
            // we are not allowed to use the same one
            char curr = board[i][j];
            board[i][j] = '#';
            if (cx >= 0 && cy >= 0 && cx < board.size() && cy < board[0].size() && 
                dfs(cx, cy, board, word, idx + 1)) {
                return true;
            }
            board[i][j] = curr;
        }
        // none worked
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // run dfs on this to see if it is the start of the word
                if (dfs(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};