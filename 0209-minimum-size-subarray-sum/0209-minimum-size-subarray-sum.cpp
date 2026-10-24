class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // this is like sliding window
        int left = 0;
        int right = 0;
        int curr_sum = nums[0];
        int min_len = (curr_sum >= target) ? 1 : INT_MAX;
        while (true) {
            if (curr_sum < target) {
                // then we should take into account what we are on and advance forward
                ++right;
                if (right == nums.size()) break;
                curr_sum += nums[right];
            } else {
                // we are greater than so how can we make shorter
                // take away what we currently have for left
                curr_sum -= nums[left];
                ++left;
            }
            if (curr_sum >= target) {
                min_len = min(min_len, right - left + 1);
            }
        }
        if (min_len == INT_MAX) return 0;
        return min_len;
    }
};