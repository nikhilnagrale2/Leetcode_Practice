/*
  Problem Link    :   https://leetcode.com/problems/sqrtx/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Cheating
class Solution {
   public:
    int mySqrt(int x) { return sqrt(x); }
};

//  Newton's Method
class Solution {
   public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) r = (r + x / r) / 2;
        return r;
    }
};

//	Binary Search Solution
//	Time Complexity - O(logn)
//	Space Complexity - O(1)
class Solution {
   public:
    int mySqrt(int x) {
        long long left = 1, right = x, ans;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

//	Binary Search Solution
//	Time Complexity - O(logn)
//	Space Complexity - O(1)
class Solution {
   public:
    int mySqrt(int x) {
        long long lo = 0, hi = x, mid;
        while (hi - lo > 1) {
            mid = lo + (hi - lo) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid <= x) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (hi * hi <= x) return hi;
        return lo;
    }
};