class Solution {
public:
    int characterReplacement(string s, int k) {
        // we should have a maxFreq like the other windows don't have to be valid
        int maxFreq = 0;
        int left = 0;
        int best = 0;
        vector<int> cnt(26, 0);
        for (int right = 0; right < s.size(); ++right) {
            // adding a character can never decrease the number of required replacements
            int idx = s[right] - 'A';
            ++cnt[idx];
            // what is the most frequent element in our array
            int freq = *max_element(cnt.begin(), cnt.end());
            while (right - left + 1 - freq > k) { // replacements must be equal to k
                --cnt[s[left] - 'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};