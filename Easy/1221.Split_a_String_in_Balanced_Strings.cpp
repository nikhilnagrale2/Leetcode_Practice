/*
  Problem Link    :   https://leetcode.com/problems/split-a-string-in-balanced-strings/

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
    int balancedStringSplit(string s)
    {
        int lr = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
                lr++;
            else
                lr--;
            if (lr == 0)
                ans++;
        }
        return ans;
    }
};