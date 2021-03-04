/*
  Problem Link    :   https://leetcode.com/problems/jewels-and-stones

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int ans = 0;
        for (int i = 0; i < S.length(); i++)
            for (int j = 0; j < J.length(); j++)
                if (S[i] == J[j])
                    ans++;
        return ans;
    }
};

//  Optimized Solution
//  Time Complexity - O(n+m) Or O(max(m,n))
//  Space Complexity - O(m)

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int ans = 0;
        set<char> setJ(J.begin(), J.end());
        for (auto x : S)
            if (setJ.count(x))
                ans++;
        return ans;
    }
};
