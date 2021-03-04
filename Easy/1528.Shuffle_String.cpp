/*
  Problem Link    :   https://leetcode.com/problems/shuffle-string

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string ans(s);
        for (int i = 0; i < s.length(); i++)
            ans[indices[i]] = s[i];
        return ans;
    }
};

//  can be done using cycle sort
//  Cycle Sort
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        const int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            while (indices[i] != i)
            {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
}