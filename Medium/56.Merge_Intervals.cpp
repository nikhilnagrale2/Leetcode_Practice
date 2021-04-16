/*
  Problem Link    :   https://leetcode.com/problems/merge-intervals/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (curr[1] < intervals[i][0])
            {
                res.push_back(curr);
                curr = intervals[i];
            }
            else
                curr[1] = max(curr[1], intervals[i][1]);
        }
        res.push_back(curr);

        return res;
    }
};

//  Brute Solution
//  Time Complexity - O(n^2)
//  Space Complexity - O(n^2)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            bool yes = true;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                int a1 = intervals[i][0];
                int a2 = intervals[i][1];

                int b1 = intervals[j][0];
                int b2 = intervals[j][1];

                if ((b1 <= a1 && a1 <= b2) || (b1 <= a2 && a2 <= b2) || (a1 <= b1 && b1 <= a2) || (a1 <= b2 && b2 <= a2))
                {
                    intervals.erase(intervals.begin() + i);
                    intervals.erase(intervals.begin() + j - 1);
                    intervals.push_back({min(a1, b1), max(a2, b2)});
                    yes = false;
                    i--;
                    break;
                }
            }
            if (yes)
                res.push_back({intervals[i][0], intervals[i][1]});
        }

        return res;
    }
};