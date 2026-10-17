class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // can we do it in O(1) space and O(n) time
        unordered_map<int, int> invToIdx;
        for (int i = 0; i < nums.size(); ++i) {
            if (invToIdx.contains(nums[i])) {
                return vector<int>{i, invToIdx[nums[i]]};
            }
            invToIdx[target - nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};