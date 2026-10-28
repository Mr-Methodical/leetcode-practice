class Solution {
public:
    bool dfs(int idx, const string &s, const vector<string> &wordDict, vector<int> &memo) {
        if (memo[idx] != 0) return (memo[idx] == 1);
        memo[idx] = -1; // assume false until later we may change it
        for (const auto &word : wordDict) {
            if (word.size() + idx > s.size()) continue; // too big
            // let's see if we can place this word here
            auto start = s.begin() + idx;
            string_view cmp_word(start, start + word.size());
            if (cmp_word == word) {
                // it will go through
                if (dfs(idx + word.size(), s, wordDict, memo)) {
                    // so it is true
                    return memo[idx] = true; // we are able to reach the end from here
                } else {
                    // we keep going through and maybe a later word will give it to us
                }
            } // else keep going not equivalent
        }
        // we get to here we weren't able to reach anything 
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size() + 1, 0); // -1 for false 1 for true we are able 
                                           //   to get to it and 0 for not explored
        memo[s.size()] = 1; // we get here it is true
        return dfs(0, s, wordDict, memo);
    }
};