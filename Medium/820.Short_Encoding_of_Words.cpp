/*
  Problem Link    :   

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//
//  Time Complexity - O(nk^2)
//  Space Complexity - O(nk)
class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> st(words.begin(), words.end());
        for (string w : st)
        {
            for (int i = 1; i < w.size(); i++)
            {
                st.erase(w.substr(i));
            }
        }
        int ans = 0;
        for (string w : st)
            ans += w.size() + 1;
        return ans;
    }
};