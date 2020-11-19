class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp)
            pairs+=(x.second)*(x.second-1)/2;
        return pairs;
    }
};