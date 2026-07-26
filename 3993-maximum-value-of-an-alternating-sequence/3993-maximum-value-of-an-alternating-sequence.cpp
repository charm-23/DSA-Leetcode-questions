class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long maxval; 
        if(n==1) return s;
        if(n==2) return s+m; 

        if(n%2==0){
            maxval= s+(1LL*(n-1)/2)*(m-1)+m; 
        }
        else{
            maxval= s+ (1LL*(n-1)/2)*(m-1) +1; 
        }

        return maxval; 
    }
};