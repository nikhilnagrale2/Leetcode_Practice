/*
  Problem Link    :
  https://leetcode.com/problems/count-of-matches-in-tournament/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Recursive
//  Time Complexity - O(logn)
//  Space Complexity - O(logn)
class Solution {
   public:
    int numberOfMatches(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n % 2 == 0) {
            return numberOfMatches(n / 2) + n / 2;
        } else {
            return numberOfMatches((n - 1) / 2 + 1) + (n - 1) / 2;
        }
    }
};

//  One Liner
//  Time Complexity - O(1)
//  Space Complexity - O(1)
class Solution {
   public:
    int numberOfMatches(int n) { return n - 1; }
};