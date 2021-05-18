/*
  Problem Link    :   https://leetcode.com/problems/network-delay-time/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Variation of Dijkstra's Algorithm
class Solution {
   public:
    typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> graph[n + 1];
        for (auto x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> vis(n + 1);
        pq.push({0, k});
        int res = 0;
        while (!pq.empty()) {
            int ud = pq.top().first, u = pq.top().second;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            res = ud;
            n--;
            for (auto nbr : graph[u]) {
                int v = nbr.first;
                int vd = nbr.second;
                if (!vis[v]) {
                    pq.push({vd + ud, v});
                }
            }
        }
        return n ? -1 : res;
    }
};