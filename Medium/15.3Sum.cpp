/*
  Problem Link    :   

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce
//  Time Complexity - O(n^3)
//  Space Complexity - O(M) - number of unique triplets
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);

                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};

//  Better Solution Using Hashing
//  Time Complexity - O(n^2logm)
//  Space Complexity - O(n)+O(M)  - where M is no of unique triplets
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]--;
            for (int j = i + 1; j < n; j++)
            {
                mp[nums[j]]--;
                int c = -(nums[i] + nums[j]);
                if (mp.find(c) != mp.end() && mp[c] != 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(c);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }

        for (auto x : st)
            ans.push_back(x);

        return ans;
    }
};

//  Optimal Solution Using Two Pointer
//  Time Complexity - O(n^2)
//  Space Complexity - O(1) - If Space for Result Matrix is not considered.
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int l = i + 1, h = n - 1, sum = -nums[i];

                while (l < h)
                    if (nums[l] + nums[h] == sum)
                    {
                        res.push_back({nums[i], nums[l], nums[h]});
                        while (l < h && nums[l] == nums[l + 1])
                            l++;
                        while (l < h && nums[h] == nums[h - 1])
                            h--;
                        l++;
                        h--;
                    }
                    else if (sum > nums[l] + nums[h])
                        l++;
                    else
                        h--;
            }

        return res;
    }
};