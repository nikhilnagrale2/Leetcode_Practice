class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size()==1) return true;
        
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        vector<pair<int,int>> v;
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        
        //we can use a comparator but I am so silly to do that.
        //as you can see i have put the values of map first in vector.
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i].first==v[i+1].first){
                return false;
            }
        }
        
        return true;
    }
};