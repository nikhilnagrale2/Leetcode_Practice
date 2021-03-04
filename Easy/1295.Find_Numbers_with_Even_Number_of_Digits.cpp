/*
  Problem Link    :   https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int n, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            n = nums[i];
            if ((10 <= n && n <= 99) || (1000 <= n && n <= 9999) || (n == 100000))
            {
                count++;
            }
        }
        return count;
    }
};

//  Solution Using Log10(n)
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
        {
            if (((int)log10(x) + 1) % 2 == 0)
                ans++;
        }
        return ans;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  But its not fast above two solutions are much faster

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
        {
            if (to_string(x).length() % 2 == 0)
                ans++;
        }
        return ans;
    }
};