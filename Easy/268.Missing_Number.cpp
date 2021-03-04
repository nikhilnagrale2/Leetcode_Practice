/*
  Problem Link    :   https://leetcode.com/problems/missing-number/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Sorting Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[nums.size() - 1] != nums.size())
        {
            return nums.size();
        }
        else if (nums[0] != 0)
        {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            int expectedNum = nums[i - 1] + 1;
            if (nums[i] != expectedNum)
            {
                return expectedNum;
            }
        }
        return -1;
    }
};

//  Set Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size(), mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

//  Set Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        set<int> numSet;
        for (int num : nums)
            numSet.insert(num);

        int expectedNumCount = nums.size() + 1;
        for (int number = 0; number < expectedNumCount; number++)
        {
            if (numSet.find(number) == numSet.end())
            {
                return number;
            }
        }
        return -1;
    }
};

//  Xor Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};

//  Gauss Formula
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        int total = (n + 1) * (n) / 2;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int missing = total - sum;
        return missing;
    }
};