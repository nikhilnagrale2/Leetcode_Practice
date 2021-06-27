/*
  Problem Link    :
  https://leetcode.com/problems/check-if-n-and-its-double-exist/submissions/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  HashSet
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        bool yes = false;
        set<int> st;
        for (auto x : arr) {
            yes |= (st.count(2 * x) || (x % 2 == 0) && st.count(x / 2));
            st.insert(x);
        }
        return yes;
    }
};

//  Binary Search
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution {
   public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int zeroCount = 0;
        for (auto x : arr) {
            if (x != 0) {
                if (binary_search(arr.begin(), arr.end(), 2 * x)) return true;
            } else
                ++zeroCount;
        }
        return zeroCount >= 2;
    }
};