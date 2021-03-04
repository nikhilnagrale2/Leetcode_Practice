/*
  Problem Link    :   

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int current = 0, highest = 0;
        for (auto x : gain)
        {
            current += x;
            highest = max(highest, current);
        }
        return highest;
    }
};