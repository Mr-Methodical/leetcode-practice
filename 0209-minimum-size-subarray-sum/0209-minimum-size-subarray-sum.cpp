class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int min_len = INT_MAX;
        int curr_sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            curr_sum += nums[right];
            while (curr_sum >= target) {
                min_len = min(min_len, right - left + 1);
                curr_sum -= nums[left++];
            }
            // on every rotation we want to be at the one slightly below so then we are adding
            // to try to see if it can go over with that, 
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};