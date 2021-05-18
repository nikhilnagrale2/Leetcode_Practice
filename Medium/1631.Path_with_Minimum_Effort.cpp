/*
  Problem Link    :   https://leetcode.com/problems/path-with-minimum-effort/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Dijkstra's Algorithm
class Solution {
   public:
    typedef pair<int, pair<int, int>> piii;
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();
        int dir[5] = {0, 1, 0, -1, 0};

        vector<vector<int>> dist(n + 1, vector<int>(m + 1, INT_MAX));
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            if (effort > dist[x][y]) continue;

            if (x == n - 1 && y == m - 1) return effort;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newDist =
                        max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (dist[nx][ny] > newDist) {
                        dist[nx][ny] = newDist;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};