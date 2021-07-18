/*
  Problem Link    :   https://leetcode.com/problems/find-a-peak-element-ii/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(m*n)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int a, b, mx = INT_MIN;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mx < mat[i][j]) mx = mat[i][j], a = i, b = j;
        return {a, b};
    }
};

//  Binary Search
//  Time Complexity - O(mlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat[0].size() - 1;
        while (l <= r) {
            int maxRow = 0, midCol = l + (r - l) / 2;
            for (int row = 0; row < mat.size(); row++) {
                maxRow = mat[row][midCol] >= mat[maxRow][midCol] ? row : maxRow;
            }
            bool lBig = midCol - 1 >= l &&
                        mat[maxRow][midCol - 1] > mat[maxRow][midCol];
            bool rBig = midCol + 1 <= r &&
                        mat[maxRow][midCol + 1] > mat[maxRow][midCol];

            if (!lBig && !rBig) {
                return vector<int>{maxRow, midCol};
            } else if (rBig)
                l = midCol + 1;
            else
                r = midCol - 1;
        }
        return {-1, -1};
    }
};