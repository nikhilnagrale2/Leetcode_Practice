/*
  Problem Link    :   https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Simple Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxcandy = *max_element(candies.begin(), candies.end());

        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++)
        {
            if (maxcandy <= candies[i] + extraCandies)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};