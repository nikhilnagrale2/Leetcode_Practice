/*
  Problem Link    :
  https://leetcode.com/problems/all-paths-from-source-to-target/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS Solution
class Solution {
   public:
    void dfs(vector<vector<int>> &paths, vector<int> &path,
             vector<vector<int>> &graph, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(path);
        } else {
            for (auto nbr : graph[node]) {
                dfs(paths, path, graph, nbr);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(paths, path, graph, 0);
        return paths;
    }
};