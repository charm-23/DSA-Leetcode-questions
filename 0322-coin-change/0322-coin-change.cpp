class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<vector<int>>dp(n, vector<int>(amount+1, INT_MAX)); 

        for(int i=0; i<n; i++){
            dp[i][0]=0; 
        }

        for(int i=1; i<=amount; i++){
            if((i%coins[0])==0) dp[0][i]=i/coins[0]; 
        }

        for(int i=1; i<n; i++){
            for(int sum=1; sum<=amount; sum++){
                int nottake=dp[i-1][sum]; 

                int take=INT_MAX; 
                if(coins[i]<=sum && dp[i][sum-coins[i]]!=INT_MAX) take= 1+ dp[i][sum-coins[i]]; 

                dp[i][sum]= min(take, nottake); 
            }
        }

        return dp[n-1][amount]==INT_MAX? -1: dp[n-1][amount]; 
    }
};