// O(n)

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int n, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            n = nums[i];
            if ((10 <= n && n <= 99) || (1000 <= n && n <= 9999) || (n == 100000))
            {
                count++;
            }
        }
        return count;
    }
};

//  O(n)
//  Using Log10(n)
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
        {
            if (((int)log10(x) + 1) % 2 == 0)
                ans++;
        }
        return ans;
    }
};

// But its not fast.
// above two solutions are much faster
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
        {
            if (to_string(x).length() % 2 == 0)
                ans++;
        }
        return ans;
    }
};