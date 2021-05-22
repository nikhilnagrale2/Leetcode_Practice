/*
  Problem Link    : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bitmasking
//  Time Complexity - O(2^n *n)
//  Space Complexity - O(1)
class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < (1 << nums.size()); i++) {
            int xors = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) xors ^= nums[j];
            }
            ans += xors;
        }
        return ans;
    }
};

//  Trick
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int bits = 0;
        for (int i = 0; i < nums.size(); ++i) bits |= nums[i];
        int ans = bits * pow(2, nums.size() - 1);
        return ans;
    }
};