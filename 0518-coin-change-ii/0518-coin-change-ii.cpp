class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(); 
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1)); 
        int res= helper(amount,n,coins,dp); 
        return res==-1? 0: res; 
    }

    int helper(int amount, int i, vector<int>& coins, vector<vector<int>>&dp){
        if(amount==0) return dp[i][0]=1; 
        if(i==0) return dp[0][amount]=0;

        if(dp[i][amount]!=-1){
            return dp[i][amount]; 
        } 

        if(coins[i-1]<=amount){
            return dp[i][amount]= helper(amount-coins[i-1], i, coins, dp) + helper(amount, i-1, coins, dp); 
        }
        else{
            return dp[i][amount]= helper(amount, i-1, coins, dp); 
        }
    }
};