/*
  Problem Link    :   https://leetcode.com/problems/rotate-image/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution using middle axis and diagonal swap
//  Time Complexity - O(n*n)
//  Space Complexity -O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - i - 1][j]);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};

//  Solution Using Transpose and Reverse - Same as Above
//  Time Complexity - O(n*n)  - beats 100%
//  Space Complexity -O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

//  Solution Using Four Group Swap
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2 + n % 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
                swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
            }
        }
    }
};