class Solution {
public:
    void backtrack(vector<vector<int>> &result, vector<int> &path, int target, int idx, vector<int> &candidates) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (idx == candidates.size()) return;
        // we should do one where we do not include it
        int curr = candidates[idx];
        while (target >= 0) {
            backtrack(result, path, target, idx + 1, candidates);
            path.push_back(curr);
            target -= curr;
        }
        // once we try every possible number of times that we can include we should remove our occurences
        // so then the person above us can try others
        while (!path.empty() && path.back() == curr) {
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        // shoudl only be putting unique ones else we might return duplicates.
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        backtrack(result, path, target, 0, candidates);
        return result;
    }
};