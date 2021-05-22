/*
  Problem Link    :   https://leetcode.com/problems/binary-watch/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Weirdo
//  Time Complexity - O(12*60)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
                                  to_string(m));
        return ans;
    }
};