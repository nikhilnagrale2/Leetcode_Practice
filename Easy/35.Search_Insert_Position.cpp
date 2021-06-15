/*
  Problem Link    :   https://leetcode.com/problems/search-insert-position/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear Search
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (target <= nums[i]) break;
        }
        return i;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid;
            else
                hi = mid;
        }
        if (nums[lo] >= target)
            return lo;
        else
            return hi;
    }
};