/*
  Problem Link    :
  https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

class Solution {
   public:
    vector<vector<int>> dist;
    int n, m, ans;
    int dfs(vector<vector<int>>& matrix, int x, int y, int parent) {
        if (x < 0 || y < 0 || x >= n || y >= m || parent >= matrix[x][y])
            return 0;
        if (dist[x][y]) return dist[x][y];
        return dist[x][y] = 1 + max({dfs(matrix, x - 1, y, matrix[x][y]),
                                     dfs(matrix, x + 1, y, matrix[x][y]),
                                     dfs(matrix, x, y - 1, matrix[x][y]),
                                     dfs(matrix, x, y + 1, matrix[x][y])});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size(), ans = 0;
        dist.resize(201, vector<int>(201, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ans = max(ans, dfs(matrix, i, j, -1));
        return ans;
    }
};