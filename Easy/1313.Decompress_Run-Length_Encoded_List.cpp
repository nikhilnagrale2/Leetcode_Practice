/*
  Problem Link    :   https://leetcode.com/problems/decompress-run-length-encoded-list

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2)
        {
            while (nums[i]--)               // Instead of while Loop we can use
                ans.push_back(nums[i + 1]); //ans.insert(ans.end(), nums[i], nums[i+1]);
        }
        return ans;
    }
};