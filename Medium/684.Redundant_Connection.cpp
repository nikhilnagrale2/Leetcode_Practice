/*
  Problem Link    :   https://leetcode.com/problems/redundant-connection/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS
//  Time Complexity - O(n^2)
//  Space Complexity - O(n)
class Solution {
   public:
    set<int> seen;
    int nodes = 1000;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> graph[nodes + 1];
        for (auto edge : edges) {
            seen.clear();
            if (!graph[edge[0]].empty() && !graph[edge[1]].empty() &&
                dfs(graph, edge[0], edge[1])) {
                return edge;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return {};
    }

   private:
    bool dfs(vector<int> graph[], int source, int target) {
        if (seen.find(source) == seen.end()) {
            seen.insert(source);
            if (source == target) return true;
            for (int nb : graph[source]) {
                if (dfs(graph, nb, target)) return true;
            }
        }
        return false;
    }
};

//  DSU
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class DSU {
    vector<int> parent;
    vector<int> rank;

   public:
    DSU(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) parent[i] = i;
        rank.resize(size);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool makeunion(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr)
            return true;
        else if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return false;
    }
};

class Solution {
   public:
    int nodes = 1000;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(nodes + 1);
        for (auto edge : edges) {
            if (dsu.makeunion(edge[0], edge[1])) return edge;
        }
        return {};
    }
};