/*
  Problem Link    :   https://leetcode.com/problems/number-of-provinces/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS Connected Component
//  Time Complexity - O(n*n)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> vis;
    void dfs(int i, vector<vector<int>>& matrix, int n) {
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && !vis[j]) {
                dfs(j, matrix, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size();
        vis.resize(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && !vis[i]) {
                    dfs(i, matrix, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};