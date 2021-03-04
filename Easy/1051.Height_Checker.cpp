/*
  Problem Link    :   https://leetcode.com/problems/height-checker/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int sum = 0;
        vector<int> beforeh;
        beforeh = heights;
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != beforeh[i])
                sum++;
        return sum;
    }
};

//  Optimized Solution Using Counting Sort
//  Time Complexity - O(n)  // almost
//  Space Complexity - O(n)

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> HeightFreq(101);

        for (int x : heights)
            HeightFreq[x]++;

        int result = 0;
        int curHeight = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (HeightFreq[curHeight] == 0)
                curHeight++;

            if (curHeight != heights[i])
                result++;

            HeightFreq[curHeight]--;
        }
        return result;
    }
};