/*
  Problem Link    :   https://leetcode.com/problems/fibonacci-number/

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

//  Naive Solution - Recursion
//  Time Complexity - O(2^n)
//  Space Complexity - O(n)

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

//  Bottom Up Approach Using Memoization
//  Time Complexity - O(n)
//  Space Complexity - O(n)
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return memoize(n);
    }

    int memoize(int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

//  DP Solution - Top Down Iterative
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int current = 0, prev1 = 0, prev2 = 1;
        for (int i = 2; i <= n; i++)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }
};

//  Matrix Exponentiation
//  Time Complexity - O(logn)
//  Space Complexity - O(logn)

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int mat[2][2] = {{1, 1}, {1, 0}};
        matrixPower(mat, n - 1);
        return mat[0][0];
    }

    void matrixPower(int mat[2][2], int n)
    {
        if (n <= 1)
            return;
        matrixPower(mat, n / 2);
        multiply(mat, mat);
        int b[2][2] = {{1, 1}, {1, 0}};
        if (n % 2 != 0)
            multiply(mat, b);
    }

    void multiply(int A[2][2], int B[2][2])
    {
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
};

//  Solution Using Benet's Formula (Golden Ratio)
//  Time Complexity - O(1)
//  Space Complexity - O(1)

class Solution
{
public:
    int fib(int n)
    {
        double goldenratio = (1 + sqrt(5)) / 2;
        return round(pow(goldenratio, n) / sqrt(5));
    }
};