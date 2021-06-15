/*
  Problem Link    :    https://leetcode.com/problems/arranging-coins/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear Search
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int arrangeCoins(int n) {
        long sum = 0;
        int i = 1;
        while (sum < n) {
            sum += i;
            if (sum > n) return i - 1;
            i++;
        }
        return i - 1;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int arrangeCoins(int n) {
        long lo = 1, hi = n, mid, curr;

        while (hi - lo >= 0) {
            mid = lo + (hi - lo) / 2;
            curr = mid * (mid + 1) / 2;
            if (curr == n) return mid;
            if (curr < n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};

//  Maths
//  Time Complexity - O(1)
//  Space Complexity - O(1)
class Solution {
   public:
    int arrangeCoins(int n) { return sqrt(2LL * n + 0.25) - 0.5; }
};