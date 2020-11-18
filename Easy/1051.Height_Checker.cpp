class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int sum=0;
        vector<int> beforeh;
        beforeh=heights;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++)
            if(heights[i]!=beforeh[i])
                sum++;
        return sum;
    }
};