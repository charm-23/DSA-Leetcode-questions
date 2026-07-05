class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(); int m=text2.size(); 
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return helper(text1, text2, n-1, m-1, dp); 
    }

    int helper(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 

        if(text1[i]==text2[j]){
            return dp[i][j]= 1+ helper(text1, text2, i-1, j-1,dp); 
        }
        else{
            return dp[i][j]=max(helper(text1, text2, i, j-1,dp), helper(text1, text2, i-1, j,dp)); 
        }
    }
};