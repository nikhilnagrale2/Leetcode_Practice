/*
  Problem Link    :   https://leetcode.com/problems/concatenation-of-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple
//  Time Complexity - O(n)
//  Space Compelxity - O(n) if ans included else O(1)
class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        for (auto x : nums) ans.push_back(x);
        return ans;
    }
};