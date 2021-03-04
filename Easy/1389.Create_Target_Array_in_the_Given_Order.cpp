/*
  Problem Link    :   https://leetcode.com/problems/create-target-array-in-the-given-order/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            result.insert(index[i] + result.begin(), nums[i]);
        }
        return result;
    }
};