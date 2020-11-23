//  Time Complexity - O(1)
//  Space Complexity - O(1)

class Solution
{
public:
    int minOperations(int n)
    {
        return n * n / 4;
    }
};

//  Time Complexity - O(logn)
//  Space Complexity - O(1)
class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
            ans += n - 2 * i - 1;
        return ans;
    }
};