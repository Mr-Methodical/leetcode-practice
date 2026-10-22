class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> numToFreq(20001, 0);
        for (int num : nums) {
            ++numToFreq[num + 10000];
        }
        // first val should be the frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> top;
        for (int i = 0; i < numToFreq.size(); ++i) {
            if (!numToFreq[i]) continue;
            top.push({numToFreq[i], i - 10000}); // the highest frequency goes to bottom
            if (top.size() > k) top.pop();
        }
        vector<int> result;
        result.reserve(k);
        while (!top.empty()) {
            result.push_back(top.top().second);
            top.pop();
        }
        return result;
    }
};