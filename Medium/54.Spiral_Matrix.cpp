/*
  Problem Link    :   https://leetcode.com/problems/spiral-matrix/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simulation
//  Time Complexity - O(M) - where M is no of cells in matrix
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int r1 = 0, c1 = 0, r2 = matrix.size() - 1, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2)
        {
            for (int i = c1; i <= c2; i++)
                ans.push_back(matrix[r1][i]);
            for (int i = r1 + 1; i <= r2; i++)
                ans.push_back(matrix[i][c2]);
            if (r1 < r2 && c1 < c2)
            {
                for (int i = c2 - 1; i > c1; i--)
                    ans.push_back(matrix[r2][i]);
                for (int i = r2; i > r1; i--)
                    ans.push_back(matrix[i][c1]);
            }
            r1++, r2--, c1++, c2--;
        }
        return ans;
    }
};

//  Easier Cleaner
//  Time Complexity - O(M)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int r1 = 0, c1 = 0, r2 = matrix.size() - 1, c2 = matrix[0].size() - 1;
        int dir = 0;
        while (r1 <= r2 && c1 <= c2)
            if (dir == 0)
            {
                for (int i = c1; i <= c2; i++)
                    ans.push_back(matrix[r1][i]);
                r1++;
                dir = 1;
            }
            else if (dir == 1)
            {
                for (int i = r1; i <= r2; i++)
                    ans.push_back(matrix[i][c2]);
                c2--;
                dir = 2;
            }
            else if (dir == 2)
            {
                for (int i = c2; i >= c1; i--)
                    ans.push_back(matrix[r2][i]);
                r2--;
                dir = 3;
            }
            else
            {
                for (int i = r2; i >= r1; i--)
                    ans.push_back(matrix[i][c1]);
                c1++;
                dir = 0;
            }
        return ans;
    }
};