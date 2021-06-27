/*
  Problem Link    :
  https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive
//  Time Complexity - O(n*n)
//  Space Complexity - O(1)
class Solution {
   public:
    int specialArray(vector<int>& nums) {
        int ans = -1;
        for (int x = 1; x <= nums.size(); x++) {
            int n = 0;
            for (auto y : nums)
                if (x <= y) n++;
            if (n == x) ans = x;
        }
        return ans;
    }
};

//  Counting Sort
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int specialArray(vector<int>& nums) {
        vector<int> v(102, 0);
        for (const auto& n : nums) {
            ++v[n > 100 ? 100 : n];
        }
        for (int i = 100; i > 0; --i) {
            v[i] = v[i + 1] + v[i];
            if (v[i] == i) return i;
        }
        return -1;
    }
};

//  Binary Search
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1, r = nums.size();
        while (r - l >= 0) {
            int m = l + (r - l) / 2;
            auto itr = lower_bound(nums.begin(), nums.end(), m);
            int c = distance(itr, nums.end());
            if (c == m)
                return m;
            else if (c > m)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};