class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &safe, vector<int> &path, int idx) {
        for (int i = 0; i < adj[idx].size(); ++i) {
            int prereq = adj[idx][i];
            if (safe[prereq]) continue; // we already know this is satisfied
            if (path[prereq]) {
                // we created a loop that is bad
                return false;
            }
            // now add it to our path because we are going to be going down
            path[prereq] = 1;
            // let's go down and see if this one has it's prereqs satisfied
            if (!dfs(adj, safe, path, prereq)) {
                return false; // if it passes though then it would set the safe to 1
            }
            // reset it:
            path[prereq] = 0;
        }
        // note that we know that this idx will always be safe now basically
        safe[idx] = 1;
        return true; // all of them worked
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // map course to prereqs
        for (int i = 0; i < prerequisites.size(); ++i) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[course].push_back(prereq);
        }
        vector<int> safe(numCourses, 0);
        vector<int> path(numCourses, 0);
        // now let's go through all 
        for (int i = 0; i < numCourses; ++i) {
            path[i] = 1; // we shouldn't go back to this
            if (!dfs(adj, safe, path, i)) {
                return false;
            }
            path[i] = 0; // reset the path array
        }
        return true;
    }
};