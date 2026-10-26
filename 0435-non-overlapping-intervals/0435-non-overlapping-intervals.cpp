class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if overlap we will just keep the smaller value
        sort(intervals.begin(), intervals.end());
        int right = intervals[0][1]; 
        int remove = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < right) {
                // then there is overlap, so we need to delete one
                ++remove;
                right = min(right, intervals[i][1]);
            } else {
                // no overlap and we just moved right further
                right = intervals[i][1];
            }
        }
        return remove;
    }
};