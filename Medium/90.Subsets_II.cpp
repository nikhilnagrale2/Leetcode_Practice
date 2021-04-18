/*
  Problem Link    :   https://leetcode.com/problems/subsets-ii/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//	Solution Using Cascading
//	Time Complexity - O(n*2^n)
//	Space Complexity - O(n*2^n)
class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        set<vector<int>> s;
        for (auto x : nums) {
            vector<vector<int>> sub = ans;
            for (int i = 0; i < sub.size(); i++) sub[i].push_back(x);
            for (auto p : sub) {
                sort(p.begin(), p.end());
                if (s.find(p) == s.end()) {
                    s.insert(p);
                    ans.push_back(p);
                }
            }
        }
        return ans;
    }
};

//	Solution Using Recursion Backtracking
//	Time Complexity - O(n*2^n)
//	Space Complexity - O(n)
class Solution {
   public:
    set<vector<int>> s;
    void backtrack(vector<int>& nums, int i, vector<int>& temp,
                   vector<vector<int>>& subs) {
        sort(temp.begin(), temp.end());
        if (s.find(temp) == s.end()) {
            subs.push_back(temp);
            s.insert(temp);
        }

        for (int j = i; j < nums.size(); j++) {
            temp.push_back(nums[j]);
            backtrack(nums, j + 1, temp, subs);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, temp, subs);
        return subs;
    }
};

//	Solution Using Bits Manipulation
//  Time Complexity - O(n*2^n)
//  Space Complexity - O(n*2^n)
class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> UniqueSubsets;
        vector<vector<int>> AllUniqueSubsets;
        int size = nums.size();
        int subSetSize = 1 << size;
        for (int subSetMask = 0; subSetMask < subSetSize; subSetMask++) {
            vector<int> subSet;
            for (int index = 0; index < size; index++) {
                if ((subSetMask & (1 << index)) != 0) {
                    subSet.push_back(nums[index]);
                }
            }
            sort(subSet.begin(), subSet.end());
            if (UniqueSubsets.find(subSet) == UniqueSubsets.end()) {
                AllUniqueSubsets.push_back(subSet);
                UniqueSubsets.insert(subSet);
            }
        }
        return AllUniqueSubsets;
    }
};