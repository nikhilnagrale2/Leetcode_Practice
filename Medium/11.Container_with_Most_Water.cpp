/*
  Problem Link    :   https://leetcode.com/problems/container-with-most-water/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce Solution  - TLE
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_water = 0;
        for (int i = 0; i < height.size(); i++)
            for (int j = i + 1; j < height.size(); j++)
                max_water = max(max_water, min(height[i], height[j]) * (j - i));

        return max_water;
    }
};

//  Optimized Two Pointer Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int width = height.size();
        int max_water = 0;
        int l = 0, r = width - 1;
        while (l != r)
        {
            int curr = min(height[l], height[r]) * --width;
            max_water = max(max_water, curr);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max_water;
    }
};