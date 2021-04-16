/*
  Problem Link    :   https://leetcode.com/problems/valid-anagram/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//  Solution Using Hashing
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> ss;
        unordered_map<char, int> st;
        for (auto c : s)
            ss[c]++;
        for (auto c : t)
            st[c]++;

        return ss == st;
    }
};

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> counts;
        for (int i = 0; i < s.size(); i++)
        {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second)
                return false;
        return true;
    }
};

//  Using array Instead as string contains only 26 small chracters
//  faster than map solution
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int counts[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
};