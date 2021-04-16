/*
  Problem Link    : https://leetcode.com/problems/longest-palindromic-substring/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  BruteForce Solution
//  Time Complexity - O(n^3)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] != s[size - i - 1]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int best_len = 0;
        string best_s = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                string subs = s.substr(i, len);
                if (len > best_len && isPalindrome(subs)) {
                    best_len = len;
                    best_s = subs;
                }
            }
        }
        return best_s;
    }
};

//  Binary Search On Answer Solution Complicated  (Errichto's Video solution)
//  ( https://www.youtube.com/watch?v=0CKUjDcUYYA )
//  Time Complexity - O(n^2logn)
//  Space Complexity - O(1)
class Solution {
   public:
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] != s[size - i - 1]) return false;
        }
        return true;
    }

    int good(int x, string s) {
        int n = s.length();
        for (int L = 0; L + x <= n; L++) {
            if (isPalindrome(s.substr(L, x))) {
                return L;
            }
        }
        return -1;
    }

    string longestPalindrome(string s) {
        int best_len = 0;
        string best_s = "";
        int size = s.size();
        for (int parity : {0, 1}) {
            int low = 1, high = size;
            if (low % 2 != parity) low++;
            if (high % 2 != parity) high--;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mid % 2 != parity) {
                    mid++;
                }
                if (mid > high) {
                    break;
                }
                int tmp = good(mid, s);
                if (tmp != -1) {
                    if (mid > best_len) {
                        best_len = mid;
                        best_s = s.substr(tmp, mid);
                    }
                    low = mid + 2;
                } else {
                    high = mid - 2;
                }
            }
        }
        return best_s;
    }
};

//  Expand Around Center
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution {
   public:
    int expandAroundCenter(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }

    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int start = 0, end = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};