class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1)); 
        int res= helper(coins,n, amount,dp); 
        return res==INT_MAX? -1 : res; 
    }

    int helper(vector<int>& coins, int i, int amount, vector<vector<int>>&dp){
        if(amount==0) return 0; 
        if(i==0) return INT_MAX;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=INT_MAX; 

        if(coins[i-1]<=amount){
            int res=helper(coins, i, amount-coins[i-1],dp); 
            if(res!=INT_MAX){
                take= 1+ res;
            }
        }

        int nottake= helper(coins, i-1, amount,dp); 

        return dp[i][amount]= min(take,nottake); 
    }
};