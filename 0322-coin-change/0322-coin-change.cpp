class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1)); 
        for(int i=0; i<=n; i++){
            dp[i][0]=0; 
        }

        for(int i=0; i<=amount; i++){
            dp[0][i]=INT_MAX; 
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int take=INT_MAX; 
                if(coins[i-1]<=j){
                    int res= dp[i][j-coins[i-1]]; 
                    if(res!=INT_MAX){
                        take=1+res; 
                    }
                }
                int nottake= dp[i-1][j]; 

                dp[i][j]= min(take,nottake); 
            }
        }

        if(dp[n][amount]==INT_MAX) return -1; 
        else return dp[n][amount]; 
    }
};