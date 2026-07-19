class Solution {
public:
    int countCommas(int n) {
        int temp=n; 
        int digits=0;
        while(n!=0){
            digits++; 
            n=n/10; 
        }

        if(digits<4) return 0;
        return temp-1000+1; 
    }
};