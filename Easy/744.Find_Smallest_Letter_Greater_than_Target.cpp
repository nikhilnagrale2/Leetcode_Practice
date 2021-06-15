/*
  Problem Link    :
  https://leetcode.com/problems/find-smallest-letter-greater-than-target/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Seen Array
//  Time Complexity - O(n)
//  Space Complexity - O(1) - no.of characters
class Solution {
   public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        vector<bool> seen(26, false);
        for (char c : letters) seen[c - 'a'] = true;

        while (true) {
            target++;
            if (target > 'z') target = 'a';
            if (seen[target - 'a']) return target;
        }
    }
};

//   Linear Search
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution {
   public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        char res = letters[0];
        for (auto x : letters)
            if (x > target) {
                res = x;
                break;
            }
        return res;
    }
};

//  Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int low = 0, high = letters.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return letters[low % letters.size()];
    }
};

//  Using Binary Search STL
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        auto x = upper_bound(letters.begin(), letters.end(), target);
        return x == letters.end() ? letters[0] : *x;
    }
};

//  Using Binary Search
//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution {
   public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int lo = 0, hi = letters.size();
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (letters[lo] > target)
            return letters[lo];
        else
            return letters[hi % letters.size()];
    }
};