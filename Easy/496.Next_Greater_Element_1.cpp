/*
  Problem Link    :   https://leetcode.com/problems/next-greater-element-i/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            bool yes = true;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums2[j] == nums1[i])
                {
                    j++;
                    while (j < nums2.size())
                    {
                        if (nums2[j] > nums1[i])
                        {
                            ans.push_back(nums2[j]);
                            yes = false;
                            break;
                        }
                        j++;
                    }
                    if (yes)
                    {
                        ans.push_back(-1);
                        break;
                    }
                    else
                        break;
                }
            }
        }
        return ans;
    }
};

//  Solution Using hashing and stack
//  Time Complexity - O(n1+n2)
//  Space Complexity - O(n1+n2)
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        stack<int> stk;
        unordered_map<int, int> mp;
        for (auto num : nums2)
        {
            while (!stk.empty() && stk.top() < num)
            {
                mp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        for (auto num : nums1)
            if (mp.find(num) != mp.end())
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);

        return ans;
    }
};

//   U can use same nums1 array for ans