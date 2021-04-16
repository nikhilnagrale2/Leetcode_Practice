/*
  Problem Link    :   https://leetcode.com/problems/binary-search/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Linear Search (I Know This is not asked in question but still)
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
                index = i;
        return index;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};