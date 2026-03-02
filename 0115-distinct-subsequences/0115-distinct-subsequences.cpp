class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(); int m=t.size(); 
        vector<vector<double>>dp(n+1, vector<double>(m+1)); 
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){ 
                if(i==0 && j==0) dp[0][0]=1;
                else if(j==0) dp[i][0]=1; 
                else if(i==0) dp[0][j]=0; 
                else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j]= dp[i-1][j] + dp[i-1][j-1]; 
                    }
                    else{
                        dp[i][j]= dp[i-1][j]; 
                    }
                }
            }
        }
        return (int)dp[n][m];
    }
};