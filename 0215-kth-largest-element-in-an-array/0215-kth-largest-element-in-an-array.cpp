class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // let's do O(klogn) for practice, this does use more space though
        priority_queue<int> maxHeap(nums.begin(), nums.end()); // heapify
        for (int i = 0; i < k - 1; ++i) maxHeap.pop();
        return maxHeap.top();
    }
};