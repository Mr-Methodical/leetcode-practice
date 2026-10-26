class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we need to find where the smallest value is
        int left = 0;
        int right = nums.size() - 1;
        // we are asking where does the change happen?
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[right]) {
                // left is the value then
                break;
            } else if (nums[left] <= nums[mid]) {
                left = mid + 1; 
            } else {
                // nums[left] > nums[mid]
                right = mid; // mid could be the value 
            }
        }
        // left is the idx of the smallest value
        // now we should binary search on it
        int smallestIdx = left;
        if (smallestIdx == 0) {
            left = 0;
            right = nums.size() - 1;
        } else if (target >= nums[0]) {
            left = 0;
            right = smallestIdx - 1;
        } else {
            left = smallestIdx;
            right = nums.size() - 1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};