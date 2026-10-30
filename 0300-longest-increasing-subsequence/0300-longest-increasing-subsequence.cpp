class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i] represents best at that index
        for (int idx = 0; idx < n; ++idx) {
            int best = max(dp[idx], 1); // starting out it counts because it is 1
            // go through all the other elements, if one is less than take the max of 
            //   best and 1 plus that other one because it can go into the other one
            for (int i = 0; i < idx; ++i) { // only look at the ones behind us
                if (nums[i] < nums[idx]) {
                    best = max(best, 1 + dp[i]);
                }
            }
            dp[idx] = best; // update with the new best that we found
        }
        return *max_element(dp.begin(), dp.end());
    }
};