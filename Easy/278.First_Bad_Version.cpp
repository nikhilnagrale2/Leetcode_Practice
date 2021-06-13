/*
  Problem Link    :   https://leetcode.com/problems/first-bad-version/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//  TLE Linear Solution
//  Time Complexity - O(n)
//  Space Complexity - O(logn)
class Solution {
   public:
    int firstBadVersion(int n) {
        for (int i = 1; i <= n; i++) {
            if (isBadVersion(i)) {
                return i;
            }
        }
        return -1;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (hi - lo > 0) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};