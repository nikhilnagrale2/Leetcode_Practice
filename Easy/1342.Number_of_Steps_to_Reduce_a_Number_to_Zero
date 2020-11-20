class Solution {
public:
    int numberOfSteps (int num) {
        int ans=0;
        while(num!=0)
        if(num%2==1){
            ans++;
            num--;
        }else{
            ans++;
            num/=2;
        }
        return ans;
    }
};

//return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
//great errichto's solution