/*
  Problem Link    :   https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

// Time Complexity - O(logn)
// Space Complexity - O(1)

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int ans = 0;
        while (num != 0)
            if (num % 2 == 1)
            {
                ans++;
                num--;
            }
            else
            {
                ans++;
                num /= 2;
            }
        return ans;
    }
};

// Great Errichto's Solution
class Solution
{
public:
    int numberOfSteps(int num)
    {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int ans = 0;
        if (!num)
            return 0;
        while (num)
        {
            ans += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return ans - 1;
    }
};

// Best Solution O(1)
// Time Complexity - O(1)
// Space Complexity - O(1)
class Solution
{
public:
    int numberOfSteps(int num)
    {
        return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
    }
};

// There's one subtlety here. log2, when rounded down, actually returns
// (the number of bits used to represent a number) minus 1.
// But that's perfect for this,
// because we don't need to shift the last 0, so that balances out nicely.
// Also note that since log2(0) is undefined, we do have to handle that case separately.