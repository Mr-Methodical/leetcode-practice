class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // tails represents the best possible ending for that particular length
        vector<int> tails;
        tails.reserve(nums.size());
        for (int n : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), n);
            if (it == tails.end()) {
                // wasn't it there so this value is the new largest 
                tails.push_back(n);
            } else {
                *it = n;
            }
        }
        return tails.size();
    }
};