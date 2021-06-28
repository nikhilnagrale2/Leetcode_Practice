/*
  Problem Link    :
  https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

//  Naive
//  Time Complexity - O(X*Y)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int i = 1; i <= 1000; i++)
            for (int j = 1; j <= 1000; j++)
                if (customfunction.f(i, j) == z) res.push_back({i, j});
        return res;
    }
};

//  Binary Search
//  Time Complexity - O(XlogY)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int x = 1; x <= 1000; ++x) {
            int l = 1, y, r = 1000;
            while (r - l > 1) {
                y = l + (r - l) / 2;
                if (customfunction.f(x, y) > z)
                    r = y;
                else
                    l = y;
            }
            if (customfunction.f(x, r) == z) res.push_back({x, r});
            if (customfunction.f(x, l) == z) res.push_back({x, l});
        }
        return res;
    }
};

//  Linear
//  Time Complexity - O(X+Y)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int y = 1000;
        for (int x = 1; x <= 1000; ++x) {
            while (y > 1 && customfunction.f(x, y) > z) y--;
            if (customfunction.f(x, y) == z) res.push_back({x, y});
        }
        return res;
    }
};

