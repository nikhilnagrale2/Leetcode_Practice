/*
  Problem Link    :   https://leetcode.com/problems/number-of-1-bits/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Using Bitset
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        bitset<32> x = n;
        return x.count();
    }
};

//  Using GCC Built in function
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }
};

//  Bit Manipulation Way
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            if (n & 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};

//  Brian Kernighan's Algorithm
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            res++;
            n &= n - 1;
        }
        return res;
    }
};
