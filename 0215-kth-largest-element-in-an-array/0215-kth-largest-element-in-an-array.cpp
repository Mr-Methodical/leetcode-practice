class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quickselect
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k; // we want k - 1 elements above an element
        random_device rd;
        mt19937 rng(rd());
        while (left <= right) {
            uniform_int_distribution<int> dist(left, right);
            int pivot = nums[dist(rng)];
            int i = left;
            int lt = left;
            int gt = right;
            while (i <= gt) {
                if (nums[i] < pivot) {
                    swap(nums[lt++], nums[i++]);
                } else if (nums[i] > pivot) {
                    swap(nums[gt--], nums[i]); // we don't have enough info about this i yet
                } else {
                    // they are equal
                    ++i;
                }
            }
            // p will end up having all the elements that are less than nums[pivotIdx] before it
            if (target > gt) {
                left = gt + 1;
            } else if (target < lt) {
                right = lt - 1;
            } else {
                // it is in the rnage of our values basically
                return nums[target];
            }
        }
        return -1; // we should not get here
    }
};