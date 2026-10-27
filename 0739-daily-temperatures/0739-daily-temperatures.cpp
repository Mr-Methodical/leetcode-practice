class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> output(temperatures.size(), 0);
        // let's have a monotonically increasing stack
        stack<pair<int, int>> temps; // val, idx
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!temps.empty() && temps.top().first <= temperatures[i]) temps.pop();
            if (!temps.empty()) output[i] = temps.top().second - i;
            temps.push(pair<int, int>(temperatures[i], i));
        }
        return output;
    }
};