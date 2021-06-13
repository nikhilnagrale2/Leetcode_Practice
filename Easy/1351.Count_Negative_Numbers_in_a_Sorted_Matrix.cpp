/*
  Problem Link    :
  https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n*n)
//  Space Complexity - O(1)
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] < 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

//  Binary Search STL
//  Time Complexity - O(nlogm) || O(mlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (auto x : grid) {
            ans += upper_bound(x.rbegin(), x.rend(), -1) - x.rbegin();
        }
        return ans;
    }
};

//  Binary Search without STL
//  Time Complexity - O(nlogm) || O(mlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (auto& v : grid) {
            int lo = 0, high = m - 1, p = m;
            while (high - lo > 1) {
                int mid = (lo + high) / 2;
                if (v[mid] > -1)
                    lo = mid + 1;
                else
                    high = mid;
            }
            if (v[lo] <= -1)
                p = lo;
            else if (v[high] <= -1)
                p = high;
            ans += m - p;
        }
        return ans;
    }
};

//  Time Complexity - O(N+M)
//  Space Complexity - O(1)
class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = 0, c = m - 1, cnt = 0;
        while (r < n && c >= 0)
            if (grid[r][c] < 0)
                --c, cnt += n - r;
            else
                ++r;
        return cnt;
    }
};