/*
  Problem Link    :   https://leetcode.com/problems/find-the-duplicate-number/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Sorting
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                return nums[i];
        return 0;
    }
};

//  Hashing
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            if (mp.find(nums[i]) != mp.end())
                return nums[i];
            else
                mp[nums[i]] = 1;
        return 0;
    }
};

//  Linked List Cycle - Floyd's Hare Tortoise Method
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//  *  Binary Search https://leetcode.com/problems/find-the-duplicate-number/discuss/72841/Java-O(1)space-using-Binary-Search
//  *  https://leetcode.com/problems/find-the-duplicate-number/discuss/705111/summary-7-solutions-with-complexity-analysis-and-explanation
