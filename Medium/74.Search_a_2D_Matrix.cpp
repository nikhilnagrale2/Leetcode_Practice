/*
  Problem Link    :   https://leetcode.com/problems/search-a-2d-matrix/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive
//  Time Complexity - O(N*N)
//  Space Complexity - O(1)
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto x : matrix)
            for (auto y : x)
                if (target == y) return true;

        return false;
    }
};

//  Binary Search
//  Time Complexity - O(log(nm))
//  Space Complexity - O(1)
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), l = 0, r = m * n - 1;
        while (l != r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};

//  Binary Search
//  Time Complexity - O(log(nm))
//  Space Complexity - O(1)
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int low;
        int high;

        // first search in first column, use binary search
        for (low = 0, high = matrix.size() - 1; low <= high;) {
            int middle = low + (high - low) / 2;
            if (matrix[middle][0] < target)
                low = middle + 1;
            else if (matrix[middle][0] > target)
                high = middle - 1;
            else
                return true;
        }

        // when above loop ends, search in row[high]
        int row = high;
        if (row >= 0) {
            for (low = 0, high = matrix[row].size() - 1; low <= high;) {
                int middle = (low + high) / 2;
                if (matrix[row][middle] < target)
                    low = middle + 1;
                else if (matrix[row][middle] > target)
                    high = middle - 1;
                else
                    return true;
            }
        }

        return false;
    }
};