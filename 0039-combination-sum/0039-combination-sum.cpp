class Solution {
public:
    void backtrack(vector<vector<int>> &result, vector<int> &path, int target, int idx, const vector<int> &candidates) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        int og_size = path.size();
        if (idx == candidates.size()) return;
        // we should do one where we do not include it
        int curr = candidates[idx];
        while (target >= 0) {
            backtrack(result, path, target, idx + 1, candidates);
            // might as well return and not let target go negative
            if (target < curr) break;
            path.push_back(curr);
            target -= curr;
        }
        path.resize(og_size); // back to original so then we can try other combinations when we backtrack
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(result, path, target, 0, candidates);
        return result;
    }
};