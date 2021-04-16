/*
  Problem Link    :   https://leetcode.com/problems/valid-palindrome-ii

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce Solution
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution
{
public:
    bool Palindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - i - 1])
                return false;
        return true;
    }

    bool validPalindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            char x = s[i];
            s.erase(s.begin() + i);
            if (Palindrome(s))
                return true;
            s.insert(s.begin() + i, x);
        }
        return Palindrome(s);
    }
};

//  Optimal Greedy Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    bool Palindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return (Palindrome(s, i + 1, j) || Palindrome(s, i, j - 1));
            }
            else
            {
                j--;
                i++;
            }
        }
        return true;
    }
};