/*
  Problem Link    :   https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Conmplexity - O(n)
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        int totalsum = 0, currsum = 0;
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (auto x : nums)
            totalsum += x;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans.push_back(nums[i]);
            currsum += nums[i];
            if (currsum > totalsum - currsum)
                break;
        }

        return ans;
    }
};

//  Solution using Priority Queue
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        vector<int> res;
        auto sub_sum = 0, half_sum = accumulate(begin(nums), end(nums), 0) / 2;
        priority_queue<int> pq(begin(nums), end(nums));
        while (sub_sum <= half_sum)
        {
            res.push_back(pq.top());
            sub_sum += res.back();
            pq.pop();
        }
        return res;
    }
}