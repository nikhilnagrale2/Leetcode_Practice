class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            result.insert(index[i]+result.begin(),nums[i]);
        }
        return result;
    }
};