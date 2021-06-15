/*
  Problem Link    :   https://leetcode.com/problems/binary-search/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear Search (I Know This is not asked in question but still)
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) index = i;
        return index;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid;
            else
                hi = mid - 1;
        }
        if (target == nums[hi])
            return hi;
        else if (target == nums[lo])
            return lo;
        else
            return -1;
    }
};