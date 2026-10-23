class Solution {
public:
    bool canJump(vector<int>& nums) {
        // we will just go through and if we ever reach 0 then
        // we stop
        int num = nums[0];
        int idx = 0;
        // if num is not greater than 0 we can't make the next step
        while (num > 0 && idx + 1 != nums.size()) {
            --num; // to get to this next step
            idx++; // make the jump to the next block
            num = max(num, nums[idx]); // we can either choose to keep with what
            // we have or go with the new value that we are on
        }
        return idx == nums.size() - 1; // we were able to reach the last index
    }
};