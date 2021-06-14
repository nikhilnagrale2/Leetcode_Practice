/*
  Problem Link    :
  https://leetcode.com/problems/peak-index-in-a-mountain-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i;
        for (i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) break;
        }
        return i;
    }
};

//  Binary Search Solution
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 1, hi = n - 2, mid = lo + (hi - lo) / 2;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid - 1] > arr[mid + 1])
                hi = mid;
            else
                lo = mid;
        }
        if (arr[lo] > arr[lo + 1] && arr[lo] > arr[lo - 1])
            return lo;
        else
            return hi;
    }
};