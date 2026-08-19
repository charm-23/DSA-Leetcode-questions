class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1)); 
        int ans=helper(0, coins, amount, dp); 
        return ans==INT_MAX? -1: ans; 
    }

    int helper(int i, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(amount==0) return 0; 
        if(i==coins.size()) return INT_MAX; 

        if(dp[i][amount]!=-1) return dp[i][amount]; 

        int take=INT_MAX; 

        if(coins[i]<=amount){
            int nxt=(helper(i,coins, amount-coins[i], dp)); 
            if(nxt!=INT_MAX){
                take= 1+ helper(i, coins, amount-coins[i], dp); 
            }
        }
        int nottake= helper(i+1, coins, amount,dp);

        return dp[i][amount]=min(take, nottake); 
    }
};