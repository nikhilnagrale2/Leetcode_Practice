/*
  Problem Link    :
  https://leetcode.com/problems/longest-repeating-character-replacement/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(26)

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, noMaxChar = 0, maxLen = 0;
        vector<int> window(26, 0);
        while (j < s.size()) {
            int index = s[j] - 'A';
            window[index] += 1;
            noMaxChar = max(noMaxChar, window[index]);
            while (j - i + 1 - noMaxChar > k) {
                window[s[i] - 'A']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};
