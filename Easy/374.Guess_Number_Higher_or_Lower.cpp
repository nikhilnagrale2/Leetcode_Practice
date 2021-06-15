/*
  Problem Link    : https://leetcode.com/problems/guess-number-higher-or-lower/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

//  Linear Search - TLE
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    int guessNumber(int n) {
        int i;
        for (i = 1; i <= n; i++) {
            if (guess(i) == 0) break;
        }
        return i;
    }
};

//  Binary Search
//  Time Complexity - O(logn) 2 base
//  Space Complexity - O(1)
class Solution {
   public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            int x = guess(mid);
            if (x == 0)
                return mid;
            else if (x == -1)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if (guess(lo) == 0)
            return lo;
        else
            return hi;
    }
};

//  TODO:Ternary Search
//  Time Complexity - O(logn) 3 base
//  Space Complexity - O(1)
