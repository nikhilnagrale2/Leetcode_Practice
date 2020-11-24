//  Naive Solution
//  Time Complexity - O(n^2)
//  Space Complexity - O(1)

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = 0; i < satisfaction.size(); i++)
        {
            int sum = 0;
            int time = 0;
            for (int j = i; j < satisfaction.size(); j++)
            {
                sum += ++time * satisfaction[j];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};

//  Prefix Sum Solution
//  Time Complexity - O(nlogn)
//  Space Complexity - O(1)

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int ans = 0, presum = 0, cur_sat = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = satisfaction.size() - 1; i >= 0; i--)
        {
            presum += satisfaction[i];
            cur_sat += presum;
            ans = max(cur_sat, ans);
        }
        return ans;
    }
};