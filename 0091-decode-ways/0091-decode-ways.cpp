class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1); 
        helper(0,s,n,dp);  
        return dp[0]; 
    }

    int helper(int i, string &s, int n, vector<int>&dp){
        if(i==n) return 1;

        if(dp[i]!=-1) return dp[i]; 
        
        if(s[i]=='0') return dp[i]=0;

        int one= helper(i+1,s,n,dp);
        int two=0; 

        if(i+1<n && s[i]=='1' || s[i]=='2' && '0'<=s[i+1] && s[i+1]<='6'){
            two= helper(i+2,s,n,dp); 
        }
        return dp[i]= one+two;  
    }
};