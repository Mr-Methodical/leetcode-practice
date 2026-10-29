class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // either a maxHeap or a minHeap could work. With a maxHeap though you would need 
        //   to push on all elements first which may not be as memory efficient though
        //   as it would be better for memory to depend on k not nums.size()
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};