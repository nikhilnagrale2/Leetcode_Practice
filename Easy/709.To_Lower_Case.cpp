/*
  Problem Link    :   https://leetcode.com/problems/to-lower-case/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Expected Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution {
   public:
    string toLowerCase(string str) {
        for (char& c : str) {
            if (c >= 'A' && c <= 'Z') c += 32;
        }
        return str;
    }
}

//  Solution Using transform
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution {
   public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

//  Bit Manipulation Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    string toLowerCase(string& str) {
        for (char& c : str) c |= 0b00100000;
        return str;
    }
}

//  credits:https://leetcode.com/problems/to-lower-case/discuss/348186/C++-Using-bit-manipulation