/*
  Problem Link    :   https://leetcode.com/problems/reducing-dishes/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :) 
*/

//  Naive Solution Using Sorting
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = 0; i < satisfaction.size(); i++)
        {
            int sum = 0;
            int time = 0;
            for (int j = i; j < satisfaction.size(); j++)
            {
                sum += ++time * satisfaction[j];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};

//  Greedy + Prefix Sum Solution (Insane Implementation)
//  For Simplicity u can find max prefix sum of prefix sum
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int ans = 0, presum = 0, cur_sat = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = satisfaction.size() - 1; i >= 0; i--)
        {
            presum += satisfaction[i];
            cur_sat += presum;
            ans = max(cur_sat, ans);
        }
        return ans;
    }
};

//  Binary Search Peak Finding Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution
{
public:
    int get_coef_sum(vector<int> s, int start)
    {
        int n = s.size();
        int sum = 0;
        int k = 0;
        for (int i = start; i < n; i++)
        {
            sum += s[i] * (k++);
        }
        return sum;
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int l = 0, r = n, middle;
        while (l < r)
        {
            middle = l + (r - l) / 2;
            int cur_sum = get_coef_sum(satisfaction, middle);
            int left = (middle == 0 || get_coef_sum(satisfaction, middle - 1) >= cur_sum) ? 1 : 0;
            int right = (middle == n - 1 || get_coef_sum(satisfaction, middle + 1) >= cur_sum) ? 1 : 0;

            if (!left && !right)
            {
                return get_coef_sum(satisfaction, middle);
            }
            else if (left)
            {
                r = middle;
            }
            else
            {
                l = middle + 1;
            }
        }
        return get_coef_sum(satisfaction, l);
    }
};

//  Recursive DP Solution (0-1 Knapsack)
//  Time Complexity - O(n^2)
//  Space Complexity - O(n^2)

class Solution
{
public:
    int dp[1000][1000];

    int function(vector<int> &satisfaction, int i, int maxT)
    {
        if (i == satisfaction.size())
            return 0;
        if (dp[i][maxT] != -1)
            return dp[i][maxT];
        int taken = function(satisfaction, i + 1, maxT);
        int not_taken = satisfaction[i] * maxT + function(satisfaction, i + 1, maxT + 1);
        return dp[i][maxT] = max(taken, not_taken);
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        memset(dp, -1, sizeof(dp));
        sort(satisfaction.begin(), satisfaction.end());
        return function(satisfaction, 0, 1);
    }
};

//  Iterative DP Solution (0-1 Knapsack)
//  Time Complexity - O(n^2)
//  Space Complexity - O(n^2)

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        int maxT = satisfaction.size();
        int t, i;
        int dp[maxT + 2][maxT + 2];
        memset(dp, 0, sizeof dp);
        for (i = maxT - 1; i >= 0; --i)
        {
            for (t = 1; t <= maxT; ++t)
            {
                if (i == maxT - 1)
                {
                    dp[i][t] = satisfaction[i] * t;
                }
                else
                {
                    dp[i][t] = max(satisfaction[i] * t + dp[i + 1][t + 1], dp[i + 1][t]);
                }
            }
        }
        return max(0, dp[0][1]);
    }
};