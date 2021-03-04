/*
  Problem Link    :   

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
    int xorOperation(int n, int start)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= start + 2 * i;
        }
        return sum;
    }
};

//  Xor Deep Dive Solution
//  Time Complexity - O(1)
//  Space Complexity - O(1)
//  https://leetcode.com/problems/xor-operation-in-an-array/discuss/796508/O(1)-time
class Solution
{
public:
    int XORforN(int val)
    {
        switch (val & 3)
        {
        case 0:
            return val;
        case 1:
            return 1;
        case 2:
            return (val + 1);
        case 3:
            return 0;
        }
        return 0;
    }

    int xorOperation(int n, int start)
    {
        return (start & 1 & n) | ((XORforN((start >> 1) + n - 1) ^ XORforN((start >> 1) - 1)) << 1);
    }
}

/*
Another O(1) solution
https://leetcode.com/problems/xor-operation-in-an-array/discuss/697849/O(1)-time

Another O(1) solution
https://leetcode.com/problems/xor-operation-in-an-array/discuss/796508/O(1)-time
*/