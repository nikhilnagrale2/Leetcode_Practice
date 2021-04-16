/*
  Problem Link    :
  https://leetcode.com/problems/search-in-rotated-sorted-array/

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
    int search(vector<int> &nums, int target) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = i;
                break;
            }
        }
        return res;
    }
};

//  Binary Search Solution
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int BinarySearch(vector<int> &nums, int target, int left, int right) {
        int mid = 0, res = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                res = mid;
                break;
            }
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }

    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int res = -1, low = 0, high = n - 1, mid;
        while (low <= high) {
            if (nums[low] <= nums[high]) {
                res = low;
                break;
            }
            mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                res = mid;
                break;
            }
            if (nums[low] <= nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (nums[res] <= target && nums[n - 1] >= target) {
            low = res;
            high = n - 1;
        } else {
            low = 0;
            high = res - 1;
        }
        return BinarySearch(nums, target, low, high);
    }
};