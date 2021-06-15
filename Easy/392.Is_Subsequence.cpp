/*
  Problem Link    :   https://leetcode.com/problems/is-subsequence/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int slen = s.size();
        int index = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[index] == t[i]) index++;
        }
        if (index == slen) return true;
        return false;
    }
};

//  Recursive
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isSub(string &s, string &t, int m, int n) {
        if (m == 0) return true;
        if (n == 0) return false;
        if (s[m - 1] == t[n - 1]) return isSub(s, t, m - 1, n - 1);
        return isSub(s, t, m, n - 1);
    }

    bool isSubsequence(string s, string t) {
        return isSub(s, t, s.size(), t.size());
    }
};

//  TODO: DP