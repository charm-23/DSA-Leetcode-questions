class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n, dp); 
    }

    int helper(int steps, vector<int>&dp){
        if(steps<=1) return dp[steps]=1; 

        if(dp[steps]!=-1) return dp[steps]; 

        return dp[steps]= helper(steps-1, dp)+ helper(steps-2,dp); 
    }
};