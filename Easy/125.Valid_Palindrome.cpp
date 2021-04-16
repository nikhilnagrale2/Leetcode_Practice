/*
  Problem Link    :   https://leetcode.com/problems/valid-palindrome/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  One Pass Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isPalindrome(string s) {
        int n = s.length();
        string s1, s2;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                s1 += tolower(s[i]);
            }
        }
        s2 = s1;
        reverse(s2.begin(), s2.end());
        return s2 == s1;
    }
};

//  Two Pointer Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j)
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (tolower(s[i]) != tolower(s[j]))
                return false;
            else
                i++, j--;

        return true;
    }
};