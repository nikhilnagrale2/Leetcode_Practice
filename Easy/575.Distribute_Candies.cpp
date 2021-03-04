/*
  Problem Link    :   https://leetcode.com/problems/distribute-candies

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution TLE
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int uniqueCandies = 0;
        for (int i = 0; i < candyType.size(); i++)
        {
            bool isUnique = true;
            for (int j = 0; j < i; j++)
            {
                if (candyType[i] == candyType[j])
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique)
            {
                uniqueCandies++;
            }
        }
        if (uniqueCandies < candyType.size() / 2)
            return uniqueCandies;
        else
            return candyType.size() / 2;
    }
};

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        sort(candyType.begin(), candyType.end());
        int uniqueCandies = 1;
        for (int i = 1; i < candyType.size() && uniqueCandies / 2 < candyType.size(); i++)
        {
            if (candyType[i] != candyType[i - 1])
            {
                uniqueCandies++;
            }
        }
        if (uniqueCandies < candyType.size() / 2)
            return uniqueCandies;
        else
            return candyType.size() / 2;
    }
};

//  Solution Using Set
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> st;
        for (auto x : candyType)
        {
            st.insert(x);
        }

        int maxCandies = candyType.size() / 2;
        if (st.size() >= maxCandies)
        {
            return maxCandies;
        }
        else
        {
            return st.size();
        }
    }
};