/*
  Problem Link    :   https://leetcode.com/problems/hamming-distance/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Easy Peasy Solution Using Bitset
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        bitset<32> a = x ^ y;
        return a.count();
    }
};

//  Using GCC built in function
class Solution
{
public:
    int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};

//  Bitwise Solution
//  Time Complexity - O(k)
//  Space Complexity - O(1)
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0, xors = x ^ y;
        while (xors)
        {
            res++;
            xors &= xors - 1;
        }
        return res;
    }
};

// * Hamming Distance and Hamming Weight