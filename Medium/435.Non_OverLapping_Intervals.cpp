/*
  Problem Link    :   https://leetcode.com/problems/non-overlapping-intervals/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
            if (curr[1] > intervals[i][0])
            {
                ans++;
                if (curr[1] > intervals[i][1])
                    curr = intervals[i];
            }
            else
                curr = intervals[i];
        return ans;
    }
};

//  TODO: DP Solution