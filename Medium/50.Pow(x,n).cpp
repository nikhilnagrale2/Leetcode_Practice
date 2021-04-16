/*
  Problem Link    :   https://leetcode.com/problems/powx-n/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        while (n--)
            ans *= x;
        return n >= 0 ? ans : 1 / ans;
    }
};

//  Fast Exponentiation
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
