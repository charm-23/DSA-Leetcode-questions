class Solution {
public:
    int hammingWeight(int n) {
        int sum=0;
        return helper(n,0); 
    }

    int helper(int n, int sum){
        if(n==0) return sum; 
        if(n%2==1) sum++; 
        return helper(n/2, sum); 
    }
};