/*
  Problem Link    :   https://leetcode.com/problems/fair-candy-swap/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sa = 0, sb = 0;
        for (auto x : a) sa += x;
        for (auto x : b) sb += x;
        for (auto x : a)
            for (auto y : b)
                if (x == y + (sa - sb) / 2) return {x, (sb - sa) / 2 + x};
        return {0, 0};
    }
};

//  Equation
//  Time Complexity - O(nlogm)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sa = 0, sb = 0;
        for (auto x : a) sa += x;
        for (auto x : b) sb += x;
        set<int> s(a.begin(), a.end());
        for (auto x : b) {
            if (s.find(x + (sa - sb) / 2) != s.end())
                return {x + (sa - sb) / 2, x};
        }
        return {0, 0};
    }
};