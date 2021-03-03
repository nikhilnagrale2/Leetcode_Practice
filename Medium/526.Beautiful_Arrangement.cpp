/*
  Problem Link    :   https://leetcode.com/problems/beautiful-arrangement/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Brute Force
//  Time Complexity - O(n!)
//  Space Complexity - O(n)

class Solution
{
public:
    int count = 0;

    void permute(vector<int> nums, int l)
    {
        if (l == nums.size() - 1)
        {
            int i;
            for (i = 1; i <= nums.size(); i++)
            {
                if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0)
                    break;
            }
            if (i == nums.size() + 1)
                count++;
        }
        for (int i = l; i < nums.size(); i++)
        {
            swap(nums[i], nums[l]);
            permute(nums, l + 1);
            swap(nums[i], nums[l]);
        }
    }

    int countArrangement(int n)
    {
        vector<int> nums(n);
        for (int i = 1; i <= n; i++)
        {
            nums[i - 1] = i;
        }
        permute(nums, 0);
        return count;
    }
};

//  Better Brute Force
//  Time complexity
//  Space Complexity - O(n)
class Solution
{
public:
    int count = 0;

    void permute(vector<int> nums, int l)
    {
        if (l == nums.size())
        {
            count++;
        }
        for (int i = l; i < nums.size(); i++)
        {
            swap(nums[i], nums[l]);
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
                permute(nums, l + 1);
            swap(nums[i], nums[l]);
        }
    }

    int countArrangement(int n)
    {
        vector<int> nums(n);
        for (int i = 1; i <= n; i++)
        {
            nums[i - 1] = i;
        }
        permute(nums, 0);
        return count;
    }
};

//  BackTracking
//  Time complexity
//  Space Complexity - O(n)

class Solution
{
public:
    int ans = 0;
    void solve(vector<bool> vis, int n, int pos)
    {
        if (pos > n)
            ans++;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] && (pos % i == 0 || i % pos == 0))
            {
                vis[i] = false;
                solve(vis, n, pos + 1);
                vis[i] = true;
            }
        }
    }

    int countArrangement(int n)
    {
        vector<bool> vis(n + 1, true);
        solve(vis, n, 1);
        return ans;
    }
};

//  Bits + BackTracking
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int seen = 0;
    int res = 0;
    int countArrangement(int n, int pos = 1)
    {
        if (n < 4)
            return n;
        if (pos > n)
            return res++;
        for (int i = 1, bit; i <= n; i++)
        {
            bit = 1 << i;
            if (!(seen & bit) && (i % pos == 0 || pos % i == 0))
            {
                // marking i as seen
                seen ^= bit;
                countArrangement(n, pos + 1);
                // backtracking
                seen ^= bit;
            }
        }
        return res;
    }
};

//  Trie Perspective Solution
//  Time Complexity - O(n)
//  https://leetcode.com/problems/beautiful-arrangement/discuss/99758/3-liner-DFS-with-%22Trie%22-perspective-(detailed-explanation-with-picture-illustration)

class solution
{
public:
    int count = 0; // count of beautiful arrangement

    int countArrangement(int N, int used = 0, int L = 1)
    {
        for (int i = 1; max(i, L) <= N; i++)
            if ((used & 1 << i) + (i % L) * (L % i) == 0)
                countArrangement(N, used ^ (1 << i), L + 1);
        return count += (L > N);
    }
};

class solution
{
public:
    int nums[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // natural ascending order

    int countArrangement(int N, int s = 1)
    { // s: start index to swap
        for (int i = s; i <= N; i++)
            if ((nums[i] % s) * (s % nums[i]) == 0)
                swap(nums[i], nums[s]), countArrangement(N, s + 1), swap(nums[i], nums[s]);
        return nums[0] += (s > N); // nums[0] used as place holder for count
    }
};

//  PreComputation
//  Time Complexity - O(1)
//  Space Complexity - O(n)
class Solution
{
public:
    int results[12] = {8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
    int countArrangement(int n)
    {
        if (n < 4)
            return n;
        return results[n - 4];
    }
};