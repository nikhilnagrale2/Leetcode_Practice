/*
  Problem Link    :   https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Stack Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> st;
        for (auto x : S)
        {
            if (!st.empty() && x == st.top())
                st.pop();
            else
                st.push(x);
        }
        string ans;
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

//  Solution Using String as Stack
//  Time Complexity - O(n)
//  Space Complexity - O(1) - if ans string is not counted
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string ans;
        for (auto x : S)
        {
            if (ans.size() && ans.back() == x)
                ans.pop_back();
            else
                ans.push_back(x);
        }
        return ans;
    }
};

// TODO: Two Pointer Solution