/*
  Problem Link    :   https://leetcode.com/problems/valid-perfect-square/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Cheating
class Solution {
   public:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        return x * x == num ? true : false;
    }
};

//  Linear Search
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPerfectSquare(int num) {
        long long x = 1;
        while (x * x <= num) {
            if (x * x == num)
                return true;
            else
                x++;
        }
        return false;
    }
};

//  Mathematical Solution
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPerfectSquare(int num) {
        int x = 1;
        while (num > 0) {
            num -= x;
            x += 2;
        }
        return num == 0;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPerfectSquare(int num) {
        long long lo = 0, hi = num, mid;
        while (hi - lo > 1) {
            mid = lo + (hi - lo) / 2;
            if (mid * mid <= num)
                lo = mid;
            else
                hi = mid - 1;
        }

        return lo * lo == num || hi * hi == num ? true : false;
    }
};

//  Newton's Method
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPerfectSquare(int num) {
        long long x = num;
        while (x * x > num) x = (x + num / x) / 2;

        return x * x == num;
    }
};

//  Newton's Method
class Solution {
   public:
    bool isPerfectSquare(int num) {
        int root = 0;
        int bit = 1 << 15;
        while (bit > 0) {
            root |= bit;
            if (root > num / root) root ^= bit;
            bit >>= 1;
        }
        return root * root == num;
    }
};