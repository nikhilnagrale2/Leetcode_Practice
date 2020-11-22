// Time complexity - O(n)
// Space comlexity - O(n)  (because I didn't do it in place) (we can easily make it O(1))
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int sum = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

// Solution Using STL
// Partial Sum Method in 
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        return nums;
    }
};