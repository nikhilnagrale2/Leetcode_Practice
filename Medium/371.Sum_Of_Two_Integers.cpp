/*
  Problem Link    :   https://leetcode.com/problems/sum-of-two-integers/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

class Solution {
   public:
    int getSum(int a, int b) {
        int c;
        while (b != 0) {
            c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};

class Solution {
   public:
    int getSum(int a, int b) { return log(pow(2, a) * pow(2, b)) / log(2); }
};