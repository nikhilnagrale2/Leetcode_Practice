/*
  Problem Link    :   

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Backtracking
//  Time Complexity - O(n*m * 4^len(word))
//  Space Complexity - O(1)
class Solution
{
public:
    int m, n;
    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int index)
    {
        if (index == word.size())
            return true;
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[i].size() - 1 || board[i][j] != word[index])
            return false;
        char c = board[i][j];
        if (c == word[index])
        {
            board[i][j] = '!';
            if (dfs(board, word, i - 1, j, index + 1))
                return true;
            if (dfs(board, word, i + 1, j, index + 1))
                return true;
            if (dfs(board, word, i, j - 1, index + 1))
                return true;
            if (dfs(board, word, i, j + 1, index + 1))
                return true;
            board[i][j] = c;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string &word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;

        return false;
    }
};