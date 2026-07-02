class Solution {
public:
    int numDecodings(string s) {
        int n=s.length(); 
        vector<int>dp(n,-1);
        return helper(0, s, dp, n); 
    }

    int helper(int i, string &s, vector<int>&dp, int n){
        if(i==n) return 1;

        if(dp[i]!=-1) return dp[i]; 

        if(s[i]=='0') return 0;

        int one= helper(i+1, s,dp,n);
        int two=0;
        if(i+1<n &&(s[i]=='1' || s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')){
            two= helper(i+2,s,dp,n); 
        }

        return dp[i]= one+two; 
    }
};