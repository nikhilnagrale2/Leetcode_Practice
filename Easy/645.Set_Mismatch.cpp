/*
  Problem Link    :   https://leetcode.com/problems/set-mismatch/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Bruteforce
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = -1;
        for (int i = 1; i <= nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                {
                    count++;
                }
            }
            if (count == 2)
                dup = i;
            else if (count == 0)
                missing = i;
        }
        return {dup, missing};
    }
};

//  Naive Solution Bruteforce
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = -1;
        for (int i = 1; i <= nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == i)
                {
                    count++;
                }
            }
            if (count == 2)
                dup = i;
            else if (count == 0)
                missing = i;
            if (dup > 0 && missing > 0)
            {
                break;
            }
        }
        return {dup, missing};
    }
};

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(logn)--> because of sorting

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int dup = -1, missing = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                dup = nums[i];
            else if (nums[i] > nums[i - 1] + 1)
                missing = nums[i - 1] + 1;
        }
        missing = nums[nums.size() - 1] != nums.size() ? nums.size() : missing;
        return {dup, missing};
    }
};

//  Solution Using maps
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        int first, second;
        for (int i = 1; i <= nums.size(); i++)
        {
            if (mp[i] == 0)
                first = i;
            if (mp[i] == 2)
                second = i;
        }
        vector<int> ans = {second, first};
        return ans;
    }
};

//  Solution Using Vector --> More memory optimized than map
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> arr(nums.size() + 1);
        int dup = -1, missing = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] == 0)
                missing = i;
            else if (arr[i] == 2)
                dup = i;
        }
        return {dup, missing};
    }
};

//  Solution Using Vector --> Constant Space
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int dup = -1, missing = -1;
        for (int n : nums)
        {
            if (nums[abs(n) - 1] < 0)
                dup = abs(n);
            else
                nums[abs(n) - 1] *= -1;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return {dup, missing};
    }
};

//  Xor Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  implementation is not good check below link
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int xorx = 0, xor0 = 0, xor1 = 0;
        for (int n : nums)
            xorx ^= n;
        for (int i = 1; i <= nums.size(); i++)
            xorx ^= i;
        int rightmostbit = xorx & ~(xorx - 1);
        for (int n : nums)
        {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        for (int i = 1; i <= nums.size(); i++)
        {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == xor0)
                return {xor0, xor1};
        }
        return {xor1, xor0};
    }
};
// https://leetcode.com/problems/set-mismatch/discuss/105513