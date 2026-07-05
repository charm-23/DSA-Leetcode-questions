class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        vector<vector<int>>dp(n, vector<int>(2,-1)); 
        return helper(prices, 0, false,dp); 
    }

    int helper(vector<int>&prices, int i, bool buy, vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy]; 

        int consider=0; int notconsider=0; 

        //buy
        if(buy==false){
            consider= -prices[i]+ helper(prices, i+1, true,dp);
            notconsider= helper(prices, i+1, false, dp); 
        }
        
        //sell
        else{
            consider= prices[i]+ helper(prices, i+2, false ,dp);
            notconsider= helper(prices, i+1,true, dp); 
        }
        return dp[i][buy]= max(consider, notconsider); 
    }
};