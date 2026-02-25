class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size(); 
        int INF = 1e9;
        vector<vector<int>> dp(n,vector<int>(amount+1,INF));
        for(int j=0; j<=amount; j++){
            if(j% coins[0]==0) dp[0][j]= j/coins[0];
        } 
        for(int i=0; i<=n-1; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n-1; i++){
            for(int j=1; j<=amount; j++){ 
                if(coins[i]<=j){
                    dp[i][j]= min(1+dp[i][j-coins[i]], dp[i-1][j]);
                }
                else{
                    dp[i][j]= dp[i-1][j]; 
                }
            }
        }
        return (dp[n-1][amount]>= INF? -1: dp[n-1][amount]);    
    }
};