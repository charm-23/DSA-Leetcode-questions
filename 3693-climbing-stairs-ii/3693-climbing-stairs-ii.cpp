class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        if(n==0) return 0;  
        dp[0]=0;
        dp[1]=costs[0]+ 1;
        if(n==1) return dp[1];  
        dp[2]=costs[1]+ min(dp[1]+1, dp[0]+4); 

        for(int i=3; i<=n; i++){
            dp[i]= costs[i-1]+ min(dp[i-3]+9, min(dp[i-1]+1, dp[i-2]+4)); 
        } 
        return dp[n]; 
    }
};