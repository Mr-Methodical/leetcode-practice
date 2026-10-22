class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> numToFreq(20001, 0);
        for (int num : nums) {
            ++numToFreq[num + 10000];
        }
        // now we go through them and we have to pick the top k frequencies basically
        // well actually we can create an array
        // where it is freq to vector of nums
        vector<vector<int>> freqToNums(nums.size() + 1);
        for (int i = 0; i < numToFreq.size(); ++i) {
            if (numToFreq[i] == 0) continue;
            freqToNums[numToFreq[i]].push_back(i - 10000);
        }
        // we will go back and push those all on they guarantee uniqueness
        vector<int> result;
        result.reserve(k);
        for (int i = static_cast<int>(freqToNums.size()) - 1; i > 0 && k > 0; --i) {
            k -= freqToNums[i].size();
            for (int num : freqToNums[i]) {
                result.push_back(num);
            }
        }
        return result;
    }
};