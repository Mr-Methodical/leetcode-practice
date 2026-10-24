class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        int idx = 1;
        for (int num : nums) {
            prefix_sum[idx] = prefix_sum[idx - 1] + num;
            ++idx;
        }
        int min_len = INT_MAX;
        // idea: we will go through all right values and use binary search to find
        //       the best left value
        for (int right = 1; right <= nums.size(); ++right) {
            // so left is giog to be between 0 and right
            int lo = 0; // indexing is slightly weird because we are using prefix sums
            int hi = right - 1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int curr_sum = prefix_sum[right] - prefix_sum[mid];
                if (curr_sum >= target) {
                    lo = mid + 1;
                    min_len = min(min_len, right - mid);
                } else {
                    hi = mid - 1;
                }
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};