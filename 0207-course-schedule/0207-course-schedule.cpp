class Solution {
public:
    bool dfs(const vector<vector<int>>& adj, vector<int> &state, int idx) {
        if (state[idx] == 1) return false; // on path, creates cycle
        if (state[idx] == 2) return true; // we already know it is safe
        state[idx] = 1; // we have visited stage

        for (int prereq : adj[idx]) {
            // confirm that this prereq is safe
            if (!dfs(adj, state, prereq)) {
                return false; 
            }
        }

        state[idx] = 2; // confirmed all prereqs good
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(numCourses);
        for (const auto &p : prereqs) {
            adj[p[0]].push_back(p[1]);
        }
        vector<int> state(numCourses, 0); // 0 = not visited, 1 = visited, 2 = prereqs satisfied
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(adj, state, i)) return false;
        }
        return true;
    }
};