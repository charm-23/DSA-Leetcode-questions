class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(); int m=p.length(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1)); 
        return helper(s, p, 0, 0,dp); 
    }

    bool helper(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        if(i==s.length() && j==p.length()) return true; 
        if(j==p.length()) return false; 
        
        if(dp[i][j]!=-1) return dp[i][j]; 

        bool notconsider= false;  bool consider=false; 
        if(j+1<p.length() && p[j+1]=='*'){
            notconsider= helper(s,p,i,j+2,dp); 

            if(i<s.length() && (s[i]==p[j] || p[j]=='.')){
                consider= helper(s,p,i+1,j,dp); 
            }
        }

        else if(i<s.length() && (s[i]==p[j] || p[j]=='.')) return dp[i][j]= helper(s, p, i+1, j+1,dp); 

        return dp[i][j]=consider|| notconsider; 
    }
};