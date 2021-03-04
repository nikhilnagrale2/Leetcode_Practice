/*
  Problem Link    :   https://leetcode.com/problems/n-th-tribonacci-number

  Author          :   Nikhil Nagrale
  Codeforces      :   https://codeforces.com/profile/nikhilnagrale2
  Codechef        :   https://www.codechef.com/users/nikhilnagrale2
  Github          :   https://github.com/nikhilnagrale2
  Leetcode        :   https://leetcode.com/nikhilnagrale2

  Copyright       :   Study and Solve. :)
*/

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

//  Recursive DP Optimized Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int calc_trib(int n, int result[])
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (result[n] == -1)
        {
            int curr_sum = calc_trib(n - 1, result) + calc_trib(n - 2, result) + calc_trib(n - 3, result);
            result[n] = curr_sum;
        }
        else
        {
            return result[n];
        }
        return result[n];
    }
    int tribonacci(int n)
    {

        int result[38];
        fill_n(result, 38, -1);

        return calc_trib(n, result);
    }
};

//  Iterative Optimized Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    int tribonacci(int n)
    {
        int dp[n + 1];
        if (n == 0)
            return 0;
        else
            dp[0] = 0;
        if (n == 1)
            return 1;
        else
            dp[1] = 1;
        if (n == 2)
            return 1;
        else
            dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        return dp[n];
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
class Solution
{
private:
    vector<vector<int>> matrixMul(const vector<vector<int>> &A, const vector<vector<int>> &B)
    {
        vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
        for (int i = 0; i < A.size(); ++i)
            for (int k = 0; k < B.size(); ++k)
                for (int j = 0; j < B[0].size(); ++j)
                {
                    C[i][j] += (A[i][k] * B[k][j]);
                }
        return C;
    }
    vector<vector<int>> matrixPow(const vector<vector<int>> &A, int k)
    {
        if (k == 0)
        {
            vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
            for (int i = 0; i < A.size(); ++i)
                C[i][i] = 1;
            return C;
        }
        if (k == 1)
            return A;

        vector<vector<int>> C = matrixPow(A, k / 2);
        C = matrixMul(C, C);
        if (k % 2 == 1)
            return matrixMul(C, A);
        return C;
    }

public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int f_0 = 0;
        int f_1 = 1;
        int f_2 = 1;

        vector<vector<int>> C = matrixPow({{1, 1, 1},
                                           {1, 0, 0},
                                           {0, 1, 0}},
                                          n - 2);
        return matrixMul(C, {{f_2},
                             {f_1},
                             {f_0}})[0][0];
    }
};