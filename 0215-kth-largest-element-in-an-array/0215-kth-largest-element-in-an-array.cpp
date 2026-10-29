class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        // maybe we binary search on which value that we think it is
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            // now how many are greater
            int count = count_if(nums.begin(), nums.end(), [mid](int x) { return x >= mid; });
            if (count >= k) {
                // we have too many so go above
                left = mid;
            } else {
                right = mid - 1;
            } 
        }
        return left;
    }
};