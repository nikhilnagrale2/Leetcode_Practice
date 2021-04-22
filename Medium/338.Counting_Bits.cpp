/*
  Problem Link    :   https://leetcode.com/problems/counting-bits/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce
//  Time Complexity - O(n*(num of bits))
//  Space Complexity - O(1) - if ans is ignored
class Solution {
   public:
    int count(int num) {
        int count = 0;
        while (num) {
            count++;
            num &= num - 1;
        }
        return count;
    }

    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; i++) ans.push_back(count(i));
        return ans;
    }
};

//  One Pass Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++) ans[i] = ans[i << 2] + (i & 1);
        return ans;
    }
};

//  One Pass Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++) ans[i] = ans[(i) & (i - 1)] + 1;
        return ans;
    }
};

//  Using GCC function
//  Time Complexity - O(n*(num of bits))
//  Space Complexity - O(1) - if ans is ignored
class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; i++) ans.push_back(__builtin_popcount(i));
        return ans;
    }
};
