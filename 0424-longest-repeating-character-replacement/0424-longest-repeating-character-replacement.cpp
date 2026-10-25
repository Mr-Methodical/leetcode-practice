class Solution {
public:
    int characterReplacement(string s, int k) {
        int best_len = 0;
        int curr_len = 0;
        for (int i = 0; i < 26; ++i) {
            // it could be any character
            char curr = 'A' + i;
            int currCnt = k;
            // we will use sliding window on this letter basically
            int left = 0;
            for (int right = 0; right < s.size(); ++right) {
                if (s[right] == curr) {
                    // good this is what we want
                } else {
                    // they are not equal so we are going to have use some of ours
                    if (currCnt == 0) {
                        while (s[left] == curr) {
                            ++left;
                        }
                        ++left; // to go past the one 
                        // we would ++currCnt but our right is already taking away
                    } else {
                        --currCnt;
                    }
                }
                curr_len = max(curr_len, right - left + 1);
            }
            best_len = max(best_len, curr_len);
        }
        return best_len;
    }
};