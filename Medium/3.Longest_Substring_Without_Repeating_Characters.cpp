/*
  Problem Link    :
  https://leetcode.com/problems/longest-substring-without-repeating-characters/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  BruteForce Solution
//  Time Coomplexity - O(n^3)
//  Space Complexity - O(n)
class Solution {
   public:
    bool isUnique(string s, int l, int r) {
        set<char> st;
        for (int i = l; i < r; i++) {
            if (st.find(s[i]) != st.end()) return false;

            st.insert(s[i]);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (isUnique(s, i, j)) ans = max(ans, j - i);

        return ans;
    }
};

//  Optimized Solution Using Set and Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0, l = 0, r = 0;
        set<char> st;
        while (l < n && r < n) {
            if (st.find(s[r]) != st.end()) {
                st.erase(s[l++]);
            } else {
                st.insert(s[r++]);
                ans = max(ans, (int)st.size());
            }
        }
        return ans;
    }
};

//  More Optimized Solution Using Set and Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0, l = 0, r = 0;
        set<char> st;
        while (r < n) {
            if (st.find(s[r]) != st.end()) {
                while (s[l] != s[r]) {
                    st.erase(s[l++]);
                }
                l++;
            } else {
                st.insert(s[r]);
                ans = max(ans, (int)st.size());
            }
            r++;
        }
        return ans;
    }
};