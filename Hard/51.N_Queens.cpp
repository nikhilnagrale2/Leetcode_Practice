/*
  Problem Link    :   https://leetcode.com/problems/n-queens/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n!)
//  Space Complexity - O(n^2)
class Solution {
   public:
    bool isValid(int row, int col, vector<string> &board, int n) {
        int drow = row, dcol = col;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        col = dcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++, col--;
        }
        col = dcol, row = drow;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--, col--;
        }
        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isValid(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board.push_back(s);
        }
        solve(0, board, ans, n);
        return ans;
    }
};

//  Time Complexity - O(n!)
//  Space Complexity - O(n^2)
class Solution {
   public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<bool> &lr, vector<bool> &ud, vector<bool> &ld, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (lr[row] == 0 && ld[row + col] == 0 &&
                ud[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                lr[row] = true, ld[row + col] = true,
                ud[n - 1 + col - row] = true;
                solve(col + 1, board, ans, lr, ud, ld, n);
                board[row][col] = '.';
                lr[row] = false, ld[row + col] = false,
                ud[n - 1 + col - row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board.push_back(s);
        }
        vector<bool> lr(n), ud(2 * n - 1), ld(2 * n - 1);
        solve(0, board, ans, lr, ud, ld, n);
        return ans;
    }
};