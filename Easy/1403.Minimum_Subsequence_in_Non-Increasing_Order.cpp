class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int totalsum=0,currsum=0;
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
        
        for(auto x:nums)
        totalsum+=x;
        
        
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(nums[i]);
            currsum+=nums[i];
            if(currsum>totalsum-currsum)
                break;
        }
        
        return ans;
    }
};