class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size());
        // let's have an array of size 101 which corresponds to where we last seen that temp
        vector<int> seen(101, -1);
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            // then we could do a loop that searches over the 70 so still constant time
            seen[temperatures[i]] = i;
            int lowestIdx = INT_MAX; // impossible idx
            for (int j = temperatures[i] + 1; j <= 100; ++j) {
                if (seen[j] == -1) continue;
                lowestIdx = min(lowestIdx, seen[j]); // so the lowest idx that we have seen for this
            }
            if (lowestIdx == INT_MAX) {
                output[i] = 0;
            } else {
                output[i] = lowestIdx - i;
            }
        }
        return output;
    }
};