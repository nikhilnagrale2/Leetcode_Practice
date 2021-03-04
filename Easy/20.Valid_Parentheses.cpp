/*
  Problem Link    :   https://leetcode.com/problems/valid-parentheses/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Using Stack
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> ans;
        ans.push('a');
        for (int i = 0; i < s.length(); i++)
        {
            if (ans.top() == '(' && s[i] == ')' || ans.top() == '[' && s[i] == ']' || ans.top() == '{' && s[i] == '}')
            {
                ans.pop();
            }
            else
            {
                ans.push(s[i]);
            }
        }
        return ans.size() - 1 ? false : true;
    }
};
