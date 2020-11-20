class Solution {
public:
    int balancedStringSplit(string s) {
        int lr=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R') lr++;
            else lr--;
            if(lr==0) ans++;
        }
        return ans;
    }
};