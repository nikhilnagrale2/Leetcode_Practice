/*
  Problem Link    :   https://leetcode.com/problems/find-the-town-judge/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  InDegree OutDegree Concept Graphs
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> cnt(N + 1, 0);
        for (auto& x : trust) cnt[x[1]]++, cnt[x[0]]--;
        for (int x = 1; x <= N; x++)
            if (cnt[x] == N - 1) return x;
        return -1;
    }
};