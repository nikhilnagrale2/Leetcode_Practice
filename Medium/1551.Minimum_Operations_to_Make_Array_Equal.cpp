/*
  Problem Link    :   https://leetcode.com/problems/minimum-operations-to-make-array-equal/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
            ans += n - 2 * i - 1;
        return ans;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        int odd = 1;
        while (odd < n)
        {
            ans += n - odd;
            odd += 2;
        }
        return ans;
    }
};

//  Time Complexity - O(1)
//  Space Complexity - O(1)

class Solution
{
public:
    int minOperations(int n)
    {
        return n * n / 4;
    }
};