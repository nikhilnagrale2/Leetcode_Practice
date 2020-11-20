class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>count(101, 0);
        for(auto x:nums){
            count[x]+=1;
        }
        int sum=0;
        for(int i=0;i<101;i++){
            if(count[i]!=0){
                int counts=count[i];
                count[i]=sum;
                sum+=counts;
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=count[nums[i]];
        }
        return nums;
    }
};