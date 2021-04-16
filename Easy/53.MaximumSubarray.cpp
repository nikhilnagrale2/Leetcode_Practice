/*
  Problem Link    :   https://leetcode.com/problems/maximum-subarray/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n^3)  - TLE
//  Space Complexity - O(1)
//  Bruteforce
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            ans = max(ans, nums[i]);

        if (ans < 0)
            return ans;

        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
            {
                int temp = 0;
                for (int k = i; k <= j; k++)
                    temp += nums[k];
                ans = max(ans, temp);
            }

        return ans;
    }
};

//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
//  Little Optimized Solution
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            ans = max(ans, nums[i]);

        if (ans < 0)
            return ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                temp += nums[j];
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  Kadane's Algo Solution
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maximum = max(maximum, nums[i]);
        }
        if (maximum < 0)
            return maximum;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            if (curr_sum < 0)
                curr_sum = 0;
            maximum = max(maximum, curr_sum);
        }
        return maximum;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  Prefix Sum Solution
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mini = 0;
        int runningSum = 0;
        int maxi = nums[0];
        for (int num : nums)
        {
            runningSum += num;
            maxi = max(maxi, runningSum - mini);
            mini = min(runningSum, mini);
        }
        return maxi;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  DP Solution - if we space Optimized it-> its called Kadane's Algo
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, nums[i]);
        }
        if (ans < 0)
            return ans;
        int dp[100000] = {};
        dp[0] = nums[0] > 0 ? nums[0] : 0;
        ans = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] + nums[i];
            if (dp[i] < 0)
                dp[i] = 0;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};