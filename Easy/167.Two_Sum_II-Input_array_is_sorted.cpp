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