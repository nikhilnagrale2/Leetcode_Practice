//  Time Limit Exceeded
//  Time Complexity - O(3^n)
//  Space Complexity - O(1)

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }
};

//  Optimized Solution - Very Good Solution - Expert Level Thinking.
//  You can do the same with three variables.
//  Time Complexity - O(n)
//  Space Complexity - O(1)

class Solution
{
public:
    int tribonacci(int n)
    {
        int dp[] = {0, 1, 1};
        for (int i = 3; i <= n; i++)
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        return dp[n % 3];
    }
};

//  Solution Using Matrix Exponentiation
//  Time Complexity - O(k^3 Logn)
//  Space Complexity - O(n*n)

//  https://leetcode.com/problems/n-th-tribonacci-number/discuss/347604/C%2B%2BO(k3log(n))-Solution-(k3)-Matrix-Exponentiation