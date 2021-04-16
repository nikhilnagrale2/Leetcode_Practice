/*
  Problem Link    :   https://leetcode.com/problems/set-matrix-zeroes/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Set
//  Time Complexity - O(n*m logn+logm)
//  Space Complexity - O(n)+O(m)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> row, col;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }

        for (auto x : row)
            for (int j = 0; j < n; j++)
                matrix[x][j] = 0;

        for (auto x : col)
            for (int i = 0; i < m; i++)
                matrix[i][x] = 0;
    }
};

//  Optimal Solution In-place
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isCol = false;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (isCol)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};