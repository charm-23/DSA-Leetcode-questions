class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        vector<vector<int>>dp(n, vector<int>(2, -1)); 
        return helper(0, prices, 1, dp); 
    }

    int helper(int index, vector<int>& prices, bool buy, vector<vector<int>>&dp){
        if(index==prices.size()) return 0; 
        int profit=0; 

        if(dp[index][buy]!=-1) return dp[index][buy]; 

        if(buy){
            profit= max(-prices[index]+ helper(index+1, prices, 0, dp), helper(index+1, prices, 1, dp)); 
        }
        else{
            profit= max(prices[index]+ helper(index+1, prices, 1, dp), helper(index+1, prices, 0, dp)); 
        }

        return dp[index][buy]=profit; 
    }
};