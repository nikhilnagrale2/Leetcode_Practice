/*
  Problem Link    :

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  DFS Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(n*m)
class Solution {
   public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool is_valid(int x, int y, vector<vector<char>> &grid,
                  vector<vector<bool>> &vis) {
        if (x < 0 || x == grid.size() || y == grid[0].size() || y < 0)
            return false;
        if (vis[x][y] == true || grid[x][y] == '0') return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<char>> &grid,
             vector<vector<bool>> &vis) {
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) {
            if (is_valid(x + dx[i], y + dy[i], grid, vis)) {
                dfs(x + dx[i], y + dy[i], grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        vector<vector<bool>> vis(grid.size(),
                                 vector<bool>(grid[0].size(), false));
        int cc = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(i, j, grid, vis), cc++;
                }
            }
        }
        return cc;
    }
};

//  DFS Solution Clever way
//  Time Complexity - O(n*m)
//  Space Complexity - O(1) - if recursion stack not counted else O(n*m) but
//  saved vis array space
class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }

    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};

//  BFS Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(n*m)
class Solution {
   public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0,
            offsets[] = {0, 1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = node.first + offsets[k],
                                y = node.second + offsets[k + 1];
                            if (x >= 0 && x < n && y >= 0 && y < m &&
                                grid[x][y] == '1') {
                                grid[x][y] = '0';
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};