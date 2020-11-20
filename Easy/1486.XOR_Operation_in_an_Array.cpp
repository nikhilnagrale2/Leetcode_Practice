class Solution {
public:
    int xorOperation(int n, int start) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum^=start+2*i;
        }
        return sum;
    }
};

/*
Another O(1) solution
https://leetcode.com/problems/xor-operation-in-an-array/discuss/697849/O(1)-time

Another O(1) solution
https://leetcode.com/problems/xor-operation-in-an-array/discuss/796508/O(1)-time
*/