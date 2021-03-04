/*
  Problem Link    :   https://leetcode.com/problems/unique-number-of-occurrences/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sort and Maps
//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        if (arr.size() == 1)
            return true;

        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        vector<pair<int, int>> v;
        for (auto x : mp)
        {
            v.push_back({x.second, x.first}); //trick to not have to use comparator
        }

        //we can use a comparator but I am so silly to do that.
        //as you can see i have put the values of map first in vector.

        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i].first == v[i + 1].first)
            {
                return false;
            }
        }
        return true;
    }
};

//  Solution Using Map and Set
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (auto n : arr)
            ++m[n];
        for (auto &p : m)
            if (!s.insert(p.second).second)
                return false;
        return true;
    }
}

