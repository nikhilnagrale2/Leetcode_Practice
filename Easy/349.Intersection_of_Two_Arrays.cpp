/*
  Problem Link    :   https://leetcode.com/problems/intersection-of-two-arrays/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> st;
        for (auto x : nums1) {
            for (auto y : nums2) {
                if (x == y) {
                    st.insert(x);
                    break;
                }
            }
        }
        for (auto x : st) res.push_back(x);
        return res;
    }
};

//  Better Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> st(nums1.begin(), nums1.end());
        for (auto x : nums2) {
            if (st.find(x) != st.end()) {
                res.push_back(x);
                st.erase(x);
            }
        }
        return res;
    }
};

//  Binary Search Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution {
   public:
    bool binarySearch(vector<int>& nums, int x) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= x) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (x == nums[hi])
            return true;
        else if (nums[lo] == x)
            return true;
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> st;
        sort(nums1.begin(), nums1.end());
        for (auto x : nums2) {
            if (binarySearch(nums1, x)) {
                st.insert(x);
            }
        }
        for (auto x : st) res.push_back(x);
        return res;
    }
};

//  Two Pointer Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> st;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                st.insert(nums1[i]);
                i++, j++;
            }
        }
        for (auto x : st) res.push_back(x);
        return res;
    }
};