/*
  Problem Link    :   https://leetcode.com/problems/remove-duplicates-from-sorted-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n+no. of duplicates)
//  Space Complexity -  O(1)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

// Optimized Using C++ STL
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

//  Most Optimized Solution Using Two Pointer Approach
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int p1 = 0;
        for (int p2 = 1; p2 < nums.size(); p2++)
        {
            if (nums[p1] != nums[p2])
            {
                nums[p1 + 1] = nums[p2];
                p1++;
            }
        }
        return p1 + 1;
    }
};