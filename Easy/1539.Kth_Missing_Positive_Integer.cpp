/*
  Problem Link    :   https://leetcode.com/problems/kth-missing-positive-number/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0, n = 1; n <= 1000; n++) {
            if (i < arr.size() && arr[i] == n)
                i++;
            else
                k--;
            if (k == 0) return n;
        }
        return 1000 + k;
    }
};

//  Linear
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int findKthPositive(vector<int>& a, int k) {
        for (int x : a)
            if (x <= k) k += 1;
        return k;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int findKthPositive(vector<int>& a, int k) {
        int l = 0, r = a.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] - (mid + 1) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l + k;
    }
};