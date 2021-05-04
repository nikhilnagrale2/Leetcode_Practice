/*
  Problem Link    :   https://leetcode.com/problems/is-graph-bipartite/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] == -1) color[node] = 1;
        for (auto x : graph[node]) {
            if (color[x] == -1) {
                color[x] = 1 - color[node];
                if (dfs(x, graph, color)) return true;
            } else if (color[x] == color[node])
                return true;
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
            if (color[i] == -1)
                if (dfs(i, graph, color)) return false;
        return true;
    }
};

//  BFS
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int nb = q.front();
            q.pop();
            for (auto x : graph[nb]) {
                if (color[x] == -1) {
                    color[x] = 1 - color[nb];
                    q.push(x);
                } else if (color[x] == color[nb])
                    return true;
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (bfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};