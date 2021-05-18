/*
  Problem Link    :   https://leetcode.com/problems/find-center-of-star-graph/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Indegree Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> indegree(n + 1, 0);
        for (auto edge : edges) {
            indegree[edge[0]]++, indegree[edge[1]]++;
        }
        for (auto edge : edges) {
            if (indegree[edge[0]] == n - 1)
                return edge[0];
            else if (indegree[edge[1]] == n - 1)
                return edge[1];
        }
        return 0;
    }
};

//  One Liner
//  Time Complexity - O(1)
//  Space Complexity - O(1)
class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]
                   ? edges[0][0]
                   : edges[0][1];
    }
};