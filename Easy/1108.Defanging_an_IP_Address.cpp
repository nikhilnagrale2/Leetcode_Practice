/*
  Problem Link    :   https://leetcode.com/problems/defanging-an-ip-address

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

// Time Complexity - O(n)
// Space Complexity - O(1)
// Best Solution
class Solution
{
public:
    string defangIPaddr(string address)
    {
        string ans;
        for (int i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                ans += "[.]";
            }
            else
            {
                ans += address[i];
            }
        }
        return ans;
    }
};

// Using regex expression
// Worst Time Complexity + Space Complexity too
// Worst solution
class Solution
{
public:
    string defangIPaddr(string address)
    {
        return regex_replace(address, regex("[.]"), "[.]");
    }
};