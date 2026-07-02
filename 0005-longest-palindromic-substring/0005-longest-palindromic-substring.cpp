class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(); 
        vector<vector<int>>dp(n, vector<int>(n,-1)); 
        int maxlen=1;
        int start=0;  

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(i,j,s,dp)){
                    if(j-i+1>maxlen){
                        start=i; 
                        maxlen= j-i+1;
                    }
                }
            }
        }
        return s.substr(start,maxlen);  
    }

    bool isPalindrome(int i, int j, string &s, vector<vector<int>>&dp){
        if(i>j) return true; 
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(s[i]!=s[j]) return dp[i][j]=false; 
        return dp[i][j]= isPalindrome(i+1, j-1, s,dp); 
    }
};