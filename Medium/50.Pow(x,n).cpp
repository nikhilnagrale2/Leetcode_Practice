/*
  Problem Link    :   https://leetcode.com/problems/powx-n/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear TLE
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    double myPow(double x, int n) {
        double ans = 1;
        long long k = abs(n);
        while (k--) ans *= x;
        return n >= 0 ? ans : 1 / ans;
    }
};

//  Fast Exponentiation
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        nn = abs(n);
        while (nn) {
            if (nn % 2) {
                nn -= 1;
                ans *= x;
            } else {
                nn /= 2;
                x *= x;
            }
        }
        return n < 0 ? 1.0 / ans : ans;
    }
};

//	Cheating
class Solution {
   public:
    double myPow(double x, int n) { return pow(x, n); }
};