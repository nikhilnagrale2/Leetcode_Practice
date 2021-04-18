/*
  Problem Link    :   https://leetcode.com/problems/subsets/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Cascading
//  Time Complexity - O(n*2^n)
//  Space Complexity - O(n*2^n)
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        for (auto x : nums) {
            vector<vector<int>> sub = ans;
            for (int i = 0; i < sub.size(); i++) sub[i].push_back(x);
            for (auto p : sub) ans.push_back(p);
        }
        return ans;
    }
};

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

//  Backtracking Solution
//  Time Complexity - O(n*2^n)
//  Space Complexity - O(n)
class Solution {
   public:
    void backtrack(vector<int>& nums, int i, vector<int>& temp,
                   vector<vector<int>>& subs) {
        subs.push_back(temp);
        for (int j = i; j < nums.size(); j++) {
            temp.push_back(nums[j]);
            backtrack(nums, j + 1, temp, subs);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> temp;
        backtrack(nums, 0, temp, subs);
        return subs;
    }
};

//  Bitmasking Solution
//  Time Complexity - O(n*2^n)
//  Space Complexity - O(n*2^n)
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int subSetSize = 1 << size;
        vector<vector<int>> subsets;
        for (int subSetMask = 0; subSetMask < subSetSize; subSetMask++) {
            vector<int> subset;
            for (int index = 0; index < nums.size(); index++) {
                if ((subSetMask & (1 << index)) != 0) {
                    subset.push_back(nums[index]);
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
};