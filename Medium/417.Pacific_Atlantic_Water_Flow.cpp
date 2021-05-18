/*
  Problem Link    :   https://leetcode.com/problems/pacific-atlantic-water-flow/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Multi Source BFS
class Solution {
   public:
    vector<vector<int>> vis;
    vector<vector<int>> ans;

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& matrix, int f) {
        int n = matrix.size(), m = matrix[0].size();
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (vis[x][y] >= f) continue;
            vis[x][y] += f;
            if (vis[x][y] == 3) ans.push_back({x, y});
            if (x + 1 < n && matrix[x + 1][y] >= matrix[x][y])
                q.push({x + 1, y});
            if (x - 1 >= 0 && matrix[x - 1][y] >= matrix[x][y])
                q.push({x - 1, y});
            if (y + 1 < m && matrix[x][y + 1] >= matrix[x][y])
                q.push({x, y + 1});
            if (y - 1 >= 0 && matrix[x][y - 1] >= matrix[x][y])
                q.push({x, y - 1});
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>> pq, aq;
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) pq.push({0, i}), aq.push({n - 1, i});
        for (int i = 0; i < n; i++) pq.push({i, 0}), aq.push({i, m - 1});
        bfs(aq, matrix, 1);
        bfs(pq, matrix, 2);
        return ans;
    }
};