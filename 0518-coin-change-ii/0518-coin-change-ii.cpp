class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size(); 

        vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(amount+1,0));

        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<=amount; i++){
            if((i%coins[0])==0) dp[0][i]=1; 
        }

        for(int i=1; i<n; i++){
            for(int sum=1; sum<=amount; sum++){
                unsigned long long nottake= dp[i-1][sum]; 
                unsigned long long take=0; 
                if(coins[i]<=sum) take=dp[i][sum-coins[i]]; 
                dp[i][sum]= (take+nottake); 
            }
        }
        return(int) dp[n-1][amount]; 
    }
};