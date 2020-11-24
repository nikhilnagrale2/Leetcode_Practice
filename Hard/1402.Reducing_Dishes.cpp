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


//  Naive Solution
//  Time Complexity - O(n)
//  Space Complexity - O(1)
