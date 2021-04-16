/*
  Problem Link    :   https://leetcode.com/problems/median-of-two-sorted-arrays/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution Using Sorting
//  Time Complexity - O((n+m)log(n+m))
//  Space Complexity - O(n+m)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (auto x : nums2)
            nums1.push_back(x);
        sort(nums1.begin(), nums1.end());
        if (nums1.size() & 1)
            return (double)nums1[nums1.size() / 2];
        return (double)(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
    }
};

//  Optimal Solution Using Binary Search -- Partition
//  Time Complexity - O(log(m+n))
//  Space Complexity - O(1)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() == 0)
            if (nums2.size() % 2 == 0)
                return (double)(nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2;
            else
                return nums2[nums2.size() / 2];

        if (nums2.size() == 0)
            if (nums1.size() % 2 == 0)
                return (double)(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
            else
                return nums1[nums1.size() / 2];

        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;
        while (low <= high)
        {
            int partitionX = low + (high - low) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && minRightX >= maxLeftY)
                if ((x + y) % 2 == 1)
                    return (double)max(maxLeftX, maxLeftY);
                else
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            else if (maxLeftX > minRightY)
                high = partitionX - 1;
            else
                low = partitionX + 1;
        }
        return -1;
    }
};