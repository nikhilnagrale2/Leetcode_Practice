/*
  Problem Link    :   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n^2)  - TLE
//  Space Complexity - O(1)
//  Bruteforce
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int best_profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (prices[j] - prices[i] > best_profit)
                    best_profit = prices[j] - prices[i];
        return best_profit;
    }
};

//  Time Complexity - O(n)
//  Space Complexity - O(1)
//  Single Pass Solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_till_now = INT_MAX;
        int best_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (min_till_now > prices[i])
                min_till_now = prices[i];
            else if (best_profit < prices[i] - min_till_now)
                best_profit = prices[i] - min_till_now;
        }
        return best_profit;
    }
};