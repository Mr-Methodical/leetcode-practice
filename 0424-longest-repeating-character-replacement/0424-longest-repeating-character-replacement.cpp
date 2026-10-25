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
            // stale is actually good, we want that. as it will never hurt us because we can't get a bigger
            // best when maxFreq stays the same. But it is helpful for keeping your size essentially
            // like in A A B A you would have maxFreq be 2 at 2nd a but then at B it would be 1 and the array would
            // shrink maybe to just A B if k = 1 we don't want this because on the next one it could just change
            // B and use 4
            maxFreq = max(maxFreq, cnt[idx]); // it only really matters what the front is because those
            // are the only ones that can actually get us something new, like even if windows aren't correct
            // with smaller values it is fine, they aren't going to get us worse. 
            // this can only ev
            if (right - left + 1 - maxFreq > k) { // replacements must be equal to k
                --cnt[s[left] - 'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};