/*
  Problem Link    :   https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Linear Search (I Know This is not asked in question but still)
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    //  firstorLast= false for first,true for last
    int LinearSearch(vector<int> &nums, int target, bool firstOrLast)
    {
        if (!nums.size())
            return -1;
        int res = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!firstOrLast && nums[i] == target)
            {
                res = i;
                return res;
            }
            if (firstOrLast && nums[nums.size() - i - 1] == target)
            {
                res = nums.size() - i - 1;
                return res;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        ans[0] = LinearSearch(nums, target, false);
        ans[1] = LinearSearch(nums, target, true);
        return ans;
    }
};

//  Solution Using Binary Search
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    //  firstorLast= false for first,true for last
    int BinarySearch(vector<int> &nums, int target, bool firstOrLast)
    {
        if (!nums.size())
            return -1;
        int mid = 0, left = 0, right = nums.size() - 1, res = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (!firstOrLast && nums[mid] == target)
            {
                res = mid;
                right = mid - 1;
                continue;
            }
            if (firstOrLast && nums[mid] == target)
            {
                res = mid;
                left = mid + 1;
                continue;
            }
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return res;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        ans[0] = BinarySearch(nums, target, false);
        ans[1] = BinarySearch(nums, target, true);
        return ans;
    }
};