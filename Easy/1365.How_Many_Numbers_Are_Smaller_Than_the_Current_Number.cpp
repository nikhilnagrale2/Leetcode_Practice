/*
  Problem Link    :   https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Bucket Sort
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> count(101, 0);
        for (auto x : nums)
        {
            count[x] += 1;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++)
        {
            if (count[i] != 0)
            {
                int counts = count[i];
                count[i] = sum;
                sum += counts;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = count[nums[i]];
        }
        return nums;
    }
};