/*
  Problem Link    :   https://leetcode.com/problems/two-sum/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n^2)  - TLE
//  Space Complexity - O(1)
//  Bruteforce Solution
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i, j;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (target - nums[i] == nums[j])
                    return {i, j};
        return {i, j};
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(n)
//  Hashing Solution
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
