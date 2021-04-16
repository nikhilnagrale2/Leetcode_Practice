/*
  Problem Link    :   https://leetcode.com/problems/merge-sorted-array/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Solution Using Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m;
        for (auto x : nums2)
            nums1[i++] = x;
        sort(nums1.begin(), nums1.end());
    }
};

//  Solution Using Insertion Sort
//  Time Complexity - O(mnlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (nums2.size() == 0)
            return;
        for (int i = 0; i < m; i++)
        {
            if (nums1[i] > nums2[0])
                swap(nums2[0], nums1[i]);

            sort(nums2.begin(), nums2.end());
        }
        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
    }
};

//  Solution Using Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];

        while (i >= 0)
            nums1[k--] = nums1[i--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

//  TODO :  GAP method
//  Time Complexity - O(n)
//  Space Complexity - O(1)
