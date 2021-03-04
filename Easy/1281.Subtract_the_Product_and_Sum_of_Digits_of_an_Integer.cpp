/*
  Problem Link    :   https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0, product = 1;
        while (n)
        {
            int unit = n % 10;
            sum += unit;
            product *= unit;
            n /= 10;
        }
        return product - sum;
    }
};