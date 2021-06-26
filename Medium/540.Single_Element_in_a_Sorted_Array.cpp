/*
  Problem Link    :
  https://leetcode.com/problems/single-element-in-a-sorted-array

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bit Manipulation
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int xors = 0;
        for (auto x : nums) xors ^= x;
        return xors;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right - left > 0) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0 && nums[mid] == nums[mid + 1] ||
                mid % 2 == 1 && nums[mid] == nums[mid - 1])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};