/*
  Problem Link    :   https://leetcode.com/problems/product-of-array-except-self/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution TLE
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)  - If Output array is not counted.
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for (int j = 0; j < nums.size(); j++)
                if (i != j)
                    product *= nums[j];

            ans[i] = product;
        }
        return ans;
    }
};

//  Solution Using left and right product arrays
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> l(n);
        vector<int> r(n);
        l[0] = 1;
        r[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            l[i] = l[i - 1] * nums[i - 1];
            r[n - i - 1] = r[n - i] * nums[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = l[i] * r[i];
        }
        return ans;
    }
};

//  Optimal Two Pass Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};