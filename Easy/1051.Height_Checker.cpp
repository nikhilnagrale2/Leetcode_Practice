//  Time Complexity - O(nlogn)
//  Space Complexity - O(n)

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int sum = 0;
        vector<int> beforeh;
        beforeh = heights;
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != beforeh[i])
                sum++;
        return sum;
    }
};

//  Optimized Solution
//  Time Complexity - O(n)  // almost
//  Space Complexity - O(n)

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> HeightFreq(101);

        for (int x : heights)
            HeightFreq[x]++;

        int result = 0;
        int curHeight = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (HeightFreq[curHeight] == 0)
                curHeight++;

            if (curHeight != heights[i])
                result++;

            HeightFreq[curHeight]--;
        }
        return result;
    }
};