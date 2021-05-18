/*
  Problem Link    :   https://leetcode.com/problems/course-schedule/

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
    bool acyclic(int node, vector<vector<int>> &adj, vector<int> &vis) {
        if (vis[node] == 2) return false;
        if (vis[node] == 1) return true;
        vis[node] = 2;
        for (auto x : adj[node]) {
            if (!acyclic(x, adj, vis)) return false;
        }
        vis[node] = 1;
        return true;
    }

    bool canFinish(int n, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(n);
        for (auto x : prerequisites) {
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0), dfsVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i] && !acyclic(i, adj, vis)) return false;
        }
        return true;
    }
};

//  BFS Solution
