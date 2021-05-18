/*
  Problem Link    :
  https://leetcode.com/problems/number-of-operations-to-make-network-connected/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS Number of Connected Component
class Solution {
   public:
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[src] = true;
        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &edges) {
        if (edges.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt - 1;
    }
};