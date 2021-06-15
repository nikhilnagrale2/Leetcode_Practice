/*
  Problem Link    : https://leetcode.com/problems/intersection-of-two-arrays-ii/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(m+n)
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int j;
            bool ok = false;
            for (j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ok = true;
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if (ok) nums2.erase(nums2.begin() + j);
        }
        return ans;
    }
};

//  Two Pointer
//  Time Complexity - O(max(m, n) log(max(m, n)))
//  Space Complexity - O(m + n)
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                ans.push_back(nums1[i]);
                i++, j++;
            }
        }
        return ans;
    }
};

//  HashTable Solution
//  Time Complexity - O(m+n)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto x : nums1) mp[x]++;
        for (auto x : nums2) {
            if (mp.find(x) != mp.end() && mp[x] >= 1) mp[x]--, ans.push_back(x);
        }
        return ans;
    }
};
