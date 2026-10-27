class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int target = 0 - nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int tot = nums[left] + nums[right];
                if (tot == target) {
                    output.push_back({nums[left], nums[right], nums[i]});
                    // we couldn't have left go again because it only works with one
                    // this is the same with right but it will just auto correct with branches
                    // further down on next rotation
                    while (left + 1 < right && nums[left + 1] == nums[left]) {
                        ++left;
                    }
                    // move to this next one
                    ++left;
                } else if (tot < target) {
                    ++left;
                } else {
                    --right; // make the tot smaller
                }
            }
            // i should only happen once because we would have above already added everything we need
            // into and we don't want duplicates
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return output;
    }
};