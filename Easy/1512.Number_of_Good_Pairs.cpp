/*
  Problem Link    :   https://leetcode.com/problems/number-of-good-pairs/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution using Maps
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int pairs = 0;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto x : mp)
            pairs += (x.second) * (x.second - 1) / 2;
        return pairs;
    }
};