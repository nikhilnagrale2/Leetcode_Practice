/*
  Problem Link    :
  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Binary Search Solution
//  Time Complexity - O(nlogm)
//  Space Complexity - O(n)
class Solution {
   public:
    int LinearSearch(vector<vector<int>>& mat, int i, int m) {
        int j;
        for (j = 0; j < m; j++)
            if (mat[i][j] == 0) break;
        return j;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int, int>> temp;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int x = LinearSearch(mat, i, m);
            temp.push_back({x, i});
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};

//  Binary Search Solution
//  Time Complexity - O(nlogm)
//  Space Complexity - O(n)
class Solution {
   public:
    int binarySearch(vector<vector<int>>& mat, int i, int m) {
        int lo = 0, hi = m - 1, ans = -1;
        while (hi - lo > 1) {
            int m = lo + (hi - lo) / 2;
            if (mat[i][m] == 1) {
                ans = m;
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        if (mat[i][hi] == 1)
            return hi + 1;
        else if (mat[i][lo] == 1)
            return lo + 1;
        else
            return 0;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int, int>> temp;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int x = binarySearch(mat, i, m);
            temp.push_back({x, i});
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};

//  U can use priority_Queue or Set Instead of Sorting
