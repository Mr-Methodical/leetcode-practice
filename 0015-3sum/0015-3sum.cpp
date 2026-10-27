class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> complement;
            // we will set this to be our number for this term
            // we need it to add to 
            int target = 0 - nums[i];
            for (int j = i + 1; j < n; ++j) {
                if (complement.contains(nums[j])) {
                    output.push_back({nums[i], nums[j], target - nums[j]});
                    // now we would need to skip over all the ones that are the same because 
                    // they would all fire with the same 
                    while (j + 1 < n && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                } else {
                    // it is new so we will just add it onto
                    // we are looking for target - nums[j];
                    complement.insert(target - nums[j]); // we could have a repeat so we don't want to skip
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                ++i;
            }
            // the first one is the fartheset we can go like once we have tried this all the possible ones
            // for this would have been discovered
        }
        return output;
    }
};