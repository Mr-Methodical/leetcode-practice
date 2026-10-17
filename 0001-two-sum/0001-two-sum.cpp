class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // can we do it in O(1) space and O(n) time
        unordered_map<int, int> invToIdx;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = invToIdx.find(nums[i]);
            if (it != invToIdx.end()) {
                return vector<int>{i, it->second};
            }
            invToIdx[target - nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};