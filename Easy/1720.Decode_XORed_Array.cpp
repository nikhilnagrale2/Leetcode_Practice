/*
  Problem Link    :   https://leetcode.com/problems/decode-xored-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ans;
        ans.push_back(first);
        for (auto &x : encoded)
        {
            ans.push_back(x ^ first);
            first = x ^ first;
        }
        return ans;
    }
};

//  Memory Optimized
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        for (auto &x : encoded)
        {
            swap(x, first);
            first = x ^ first;
        }
        encoded.push_back(first);
        return encoded;
    }
};

//  Memory Optimized
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        encoded.insert(encoded.begin(), first);
        for (int i = 1; i < encoded.size(); i++)
            encoded[i] ^= encoded[i - 1];
        return encoded;
    }
};