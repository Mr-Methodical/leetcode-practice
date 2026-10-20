class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        int l = 0;
        int r = 0;
        int curr_max = 0;
        int abs_max = 0;
        vector<int> idxLastSeen(256, -1); // for number of characters there are
        // keep going with r till tit gets past the end
        while (r != s.size()) {
            int pos = s[r];
            int idxLast = idxLastSeen[pos];
            int nxt = idxLast + 1; // because we would want l to move to the next one
            idxLastSeen[pos] = r; // we have now seen occurence here
            l = max(l, nxt);
            curr_max = r - l + 1;
            abs_max = max(abs_max, curr_max);
            ++r;
        }
        return abs_max;
    }
};