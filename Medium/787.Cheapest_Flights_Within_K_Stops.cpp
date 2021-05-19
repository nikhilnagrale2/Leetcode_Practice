/*
  Problem Link    :
  https://leetcode.com/problems/cheapest-flights-within-k-stops/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Dijakstra's Algorithm
//  TLE
class Solution {
    typedef pair<int, pair<int, int>> piii;

   public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0, {src, k + 1}});
        while (!pq.empty()) {
            auto node = pq.top();
            int u = node.second.first, ud = node.first,
                left = node.second.second;
            pq.pop();
            if (u == dst) return ud;

            if (left == 0) continue;
            for (auto &nbr : adj[u]) {
                int v = nbr.first, vd = nbr.second;
                pq.push({vd + ud, {v, left - 1}});
            }
        }
        return -1;
    }
};

//  Bellman Ford Algorihtm
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> tmp(dist);
            for (auto flight : flights) {
                int u = flight[0], v = flight[1], wt = flight[2];
                if (dist[u] != INT_MAX) tmp[v] = min(tmp[v], dist[u] + wt);
            }
            dist = tmp;
        }
        if (dist[dst] != INT_MAX)
            return dist[dst];
        else
            return -1;
    }
};