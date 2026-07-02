class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1); 
        return helper(n, costs,dp); 
    }

    int helper(int n, vector<int>&costs, vector<int>&dp){
        if(n==0) return dp[0]=0; 
        if(n<0) return INT_MAX; 

        if(dp[n]!=-1) return dp[n]; 

        long long jump1= helper(n-1, costs, dp);
        long long jump2= helper(n-2, costs, dp); 
        long long jump3= helper(n-3, costs, dp);

        int mincost= min(jump3+9,min(jump1+1, jump2+4)); 

        return dp[n]= mincost+ costs[n-1]; 
    }
};