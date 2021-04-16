/*
  Problem Link    :   https://leetcode.com/problems/insert-interval/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  One Pass Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[1] < intervals[i][0])
            {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};