/*
  Problem Link    :   https://leetcode.com/problems/top-k-frequent-elements/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(nlogk)
//  Space Complexity - O(n+k)
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        auto comp = [&mp](int n1, int n2) { return mp[n1] > mp[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto x : mp) {
            pq.push({x.first});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};