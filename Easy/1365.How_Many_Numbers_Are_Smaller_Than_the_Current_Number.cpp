//  Naive Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> count(101, 0);
        for (auto x : nums)
        {
            count[x] += 1;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++)
        {
            if (count[i] != 0)
            {
                int counts = count[i];
                count[i] = sum;
                sum += counts;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = count[nums[i]];
        }
        return nums;
    }
};

//  Solution Using Cycle Sort
//  Time Complexity - O(n)
//  Space Complexity - O(1)
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        for (int i = 0; i < indices.size(); i++)
        {
            while (indices[i] != i)
            {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};