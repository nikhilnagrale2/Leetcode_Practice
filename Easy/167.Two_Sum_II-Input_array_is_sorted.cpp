// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            if (target > numbers[i] + numbers[j])
                i++;
            else if (target < numbers[i] + numbers[j])
                j--;
            else
                break;
        }
        vector<int> ans;
        ans.push_back(i + 1);
        ans.push_back(j + 1);

        return ans;
    }
};

//can be done using binary search (nlogn)
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/942235/C%2B%2B-Two-Pointers-or-O(n)-and-Binary-Search-or-O(n-log-n)

//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> sums;
        for (int i = 0; i < numbers.size(); i++)
        {
            int low = 0, high = numbers.size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (numbers[mid] == target - numbers[i])
                {
                    if (mid == i)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        sums = {i + 1, mid + 1};
                        return sums;
                    }
                }
                else if (numbers[mid] < target - numbers[i])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return sums;
    }
};