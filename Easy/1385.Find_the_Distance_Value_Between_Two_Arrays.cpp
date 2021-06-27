/*
  Problem Link    :
  https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)
class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (auto x : arr1) {
            int mins = INT_MAX;
            for (auto y : arr2) {
                mins = min(abs(x - y), mins);
            }
            if (mins <= d) ans++;
        }
        return arr1.size() - ans;
    }
};

//  STL
//  Time Complexity - O(n*m)
//  Space Complexity - O(1)
class Solution {
   public:
    int findTheDistanceValue(vector<int>& A, vector<int>& B, int d) {
        return count_if(begin(A), end(A), [&](const auto& a) {
            return all_of(begin(B), end(B),
                          [&](const auto& b) { return abs(a - b) > d; });
        });
    }
};

//  Binary Search STL
//  Time Complexity - O(nlogm)
//  Space Complexity - O(1)
class Solution {
   public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans = 0;
        sort(b.begin(), b.end());
        for (auto x : a) {
            if ((upper_bound(b.begin(), b.end(), x + d) ==
                 lower_bound(b.begin(), b.end(), x - d)))
                ans++;
        }
        return ans;
    }
};

//  Binary Search
//  Time Complexity - O(nlogm)
//  Space Complexity - O(1)
class Solution {
   public:
    int upperbound(vector<int>& v, int to_find) {
        int low = 0, high = v.size() - 1;
        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (v[mid] <= to_find) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (v[low] > to_find)
            return low;
        else if (v[high] > to_find)
            return high;
        return -1;
    }

    int lowerbound(vector<int>& v, int to_find) {
        int low = 0, high = v.size() - 1;
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (v[mid] < to_find) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (v[low] >= to_find)
            return low;
        else if (v[high] >= to_find)
            return high;
        return -1;
    }

    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans = 0;
        sort(b.begin(), b.end());
        for (auto x : a) {
            if ((upperbound(b, x + d) == lowerbound(b, x - d))) ans++;
        }
        return ans;
    }
};