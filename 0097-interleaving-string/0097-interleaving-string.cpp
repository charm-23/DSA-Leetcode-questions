class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(); int m=s2.length(); 
        if(s3.length()!=n+m) return false; 
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1)); 
        return helper(s1, s2, s3, 0, 0, dp); 
    }

    bool helper(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>>&dp){
        if(i+j==s3.length()) return true; 
        if(i<s1.length() && j<s2.length() && s3[i+j]!=s1[i] && s3[i+j]!=s2[j]) return false;

        if(dp[i][j]!=-1) return dp[i][j];  
        
        if(i<s1.length() && j<s2.length() && s3[i+j]==s2[j] && s3[i+j]==s1[i]){
            return dp[i][j]= helper(s1, s2, s3, i+1, j, dp) || helper(s1, s2, s3, i, j+1, dp); 
        }

        if(i<s1.length() && s3[i+j]==s1[i]){
            return dp[i][j]= helper(s1, s2, s3, i+1, j,dp); 
        }

        else if(j<s2.length() && s3[i+j]==s2[j]){
            return dp[i][j]=helper(s1, s2, s3, i, j+1,dp);
        }
        return false; 
    }
};