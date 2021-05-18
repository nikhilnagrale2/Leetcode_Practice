/*
  Problem Link    :
  https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  no Indegree Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> in(n, 0);
        for (auto edge : edges) {
            in[edge[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};