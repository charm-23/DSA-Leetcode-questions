class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,(vector<int>(amount+1,-1)));  
        helper(coins, amount, 0, dp); 
        return dp[0][amount]==INT_MAX?-1: dp[0][amount]; 
    }

    int helper(vector<int>& coins, int amount, int index, vector<vector<int>>&dp){
        if(amount==0) return dp[index][0]=0; 
        if(index==coins.size()) return INT_MAX; 

        if(dp[index][amount]!=-1){
            return dp[index][amount]; 
        }
        
        int take=INT_MAX; 
        if(coins[index]<=amount){
            int res=helper(coins, amount-coins[index], index,dp);
            if(res!= INT_MAX){
                take= 1+ res; 
            }
        }
        int nottake= helper(coins, amount, index+1,dp); 

        return dp[index][amount]= min(take, nottake);
    }
};