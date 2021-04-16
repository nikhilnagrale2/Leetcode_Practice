/*
  Problem Link    :   https://leetcode.com/problems/group-anagrams/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sorting
//  Time Complexity - O(nklogk)
//  Space Complexity - O(nk)
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        map<string, vector<string>> mp;
        for (auto x : strs) {
            auto p = x;
            sort(x.begin(), x.end());
            mp[x].push_back(p);
        }
        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

//  Solution Using Hashing
//  Time Complexity - O(nk)
//  Space Complexity - O(nk)
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<vector<int>, vector<string>> mp;
        for (auto x : strs) {
            vector<int> cnt(26, 0);
            for (char c : x) {
                cnt[c - 'a']++;
            }
            mp[cnt].push_back(x);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};