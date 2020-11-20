class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n){
            int unit=n%10;
            sum+=unit;
            product*=unit;
            n/=10;
        }
        return product-sum;
    }
};