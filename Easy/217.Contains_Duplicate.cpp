/*
  Problem Link    :   https://leetcode.com/problems/contains-duplicate/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce Solution - TLE
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return true;
        return false;
    }
};

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};

//  Solution Using Hashing || Set
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
            if (st.find(nums[i]) != st.end())
                return true;
            else
                st.insert(nums[i]);
        return false;
    }
};
