/*
  Problem Link    :   https://leetcode.com/problems/sort-colors/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

// 	Counting Array
//	Time Complexity - O(n)
//	Space Compelxity - O(1)
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for (auto x : nums) count[x]++;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (count[j] == 0) j++;
            nums[i] = j;
            count[j]--;
        }
    }
};

//	Follow Up
//	Dutch National Flag Algorithm
//	Time Complexity - O(n)
//	Space Complexity - O(1)
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[low++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};

//	Cheating
//	time Complexity - O(nlogn)
//	Space Complexity - O(1)
class Solution {
   public:
    void sortColors(vector<int>& nums) { sort(nums.begin(), nums.end()); }
};