/*
  Problem Link    :   https://leetcode.com/problems/trapping-rain-water/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Bruteforce Solution
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int l = 0, r = 0;
            for (int j = 0; j <= i; j++)
                l = max(l, height[j]);
            for (int j = i; j < height.size(); j++)
                r = max(r, height[j]);
            sum += min(l, r) - height[i];
        }
        return sum;
    }
};

//  Solution Prefix and Suffix max
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (!height.size())
            return 0;
        int sum = 0;
        int size = height.size();
        vector<int> l(size), r(size);

        l[0] = height[0];
        r[size - 1] = height[size - 1];

        for (int i = 1; i < size; i++)
        {
            l[i] = max(l[i - 1], height[i]);
            r[size - i - 1] = max(r[size - i], height[size - i - 1]);
        }

        for (int i = 0; i < size; i++)
            sum += min(l[i], r[i]) - height[i];

        return sum;
    }
};

//  Stack Approach
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0, index = 0;
        stack<int> st;
        while (index < height.size())
        {
            while (!st.empty() && height[index] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int dis = index - st.top() - 1;
                int min_height = min(height[index], height[st.top()]) - height[top];
                sum += dis * min_height;
            }
            st.push(index++);
        }
        return sum;
    }
};

//  Best Implementation - Two Pointer
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n < 3)
            return 0;
        int sum = 0, i = 0, j = n - 1;
        int left_max = height[0], right_max = height[n - 1];
        while (i <= j)
        {
            left_max = max(height[i], left_max), right_max = max(height[j], right_max);
            if (left_max <= right_max)
                sum += left_max - height[i++];
            else if (right_max <= left_max)
                sum += right_max - height[j--];
        }
        return sum;
    }
};

//  Two Pointer Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (!height.size())
            return 0;
        int size = height.size();
        int l = 0, r = size - 1, min_height = 0, sum = 0;
        while (l < r)
        {
            while (l < r && height[l] <= min_height)
                sum += min_height - height[l++];
            while (l < r && height[r] <= min_height)
                sum += min_height - height[r--];

            min_height = min(height[l], height[r]);
        }

        return sum;
    }
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int sum = 0;
        int max_left = 0, max_right = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= max_left)
                    max_left = height[left];
                else
                    sum += max_left - height[left];
                left++;
            }
            else
            {
                if (height[right] >= max_right)
                    max_right = height[right];
                else
                    sum += max_right - height[right];
                right--;
            }
        }

        return sum;
    }
};
