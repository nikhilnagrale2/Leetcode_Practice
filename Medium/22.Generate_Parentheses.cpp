/*
  Problem Link    :   https://leetcode.com/problems/generate-parentheses/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Backtracking
class Solution {
   public:
    void generate(string curr, int l, int r, vector<string>& ans) {
        if (l) generate(curr + '(', l - 1, r, ans);
        if (r > l) generate(curr + ')', l, r - 1, ans);
        if (!r) ans.push_back(curr);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        generate(curr, n, n, ans);
        return ans;
    }
};