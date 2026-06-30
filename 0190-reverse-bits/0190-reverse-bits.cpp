class Solution {
public:
    int reverseBits(int n) {
        if (n==0) return n; 
        int result=0; 
        for(int i=0; i<32; i++){
            result=result<<1; 
            int lsb= n&1; 
            result= result|lsb; 
            n=n>>1; 
        }
    return result;
    }
};