class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> lastSeen; // stack allocated not dynamimcally allocated = slightly faster
        lastSeen.fill(-1);
        int left = 0;
        int bestLength = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char c = s[right];
            // we don't want to go backwards so we will take the max
            left = max(left, lastSeen[c] + 1);
            lastSeen[c] = right;
            bestLength = max(bestLength, right - left + 1);
        }
        return bestLength;
    }
};