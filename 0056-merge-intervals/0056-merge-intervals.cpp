class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i < (intervals.size() - 1) && end >= intervals[i + 1][0]) {
                ++i;
                end = max(end, intervals[i][1]);
            }
            result.push_back({start, end});
        }
        return result;
    }
};