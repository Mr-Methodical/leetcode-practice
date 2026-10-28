class Solution {
public:
    bool dfs(int idx, const string &s, const vector<string> &wordDict, vector<int> &memo) {
        if (memo[idx] != 0) return (memo[idx] == 1);
        for (const auto &word : wordDict) {
            if (word.size() + idx <= s.size() && s.compare(idx, word.size(), word) == 0 &&
                dfs(idx + word.size(), s, wordDict, memo)){
                return memo[idx] = 1;
            }
        }
        // we get to here we weren't able to reach anything 
        memo[idx] = -1; 
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size() + 1, 0); // -1 for false 1 for true we are able 
                                           //   to get to it and 0 for not explored
        memo[s.size()] = 1; // we get here it is true
        return dfs(0, s, wordDict, memo);
    }
};