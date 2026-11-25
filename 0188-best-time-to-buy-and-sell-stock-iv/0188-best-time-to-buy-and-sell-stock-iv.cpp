class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1))); 
        return helper(0, prices, 1, k, dp); 
    }

    int helper(int index, vector<int>&prices, bool buy, int k, vector<vector<vector<int>>>&dp){
        if(k==0) return 0; 
        if(index==prices.size()) return 0; 
        int profit=0; 

        if(dp[index][buy][k]!=-1) return dp[index][buy][k]; 

        if(buy){
            profit= max(-prices[index]+ helper(index+1, prices, 0, k, dp), helper(index+1, prices, 1, k, dp)); 
        }
        else{
            profit= max(prices[index]+ helper(index+1, prices, 1, k-1, dp), helper(index+1, prices, 0, k, dp)); 
        }
        return dp[index][buy][k]=profit; 
    }
};