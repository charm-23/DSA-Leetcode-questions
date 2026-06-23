class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(); 
        int start=0; 
        vector<vector<int>>dp(n, vector<int>(n,-1)); 
        int maxlen=0; 
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(isPalindrome(s,i,j,dp)==true){
                    int len=j-i+1;
                    if(len>maxlen) start=i; 
                    maxlen= max(maxlen, len);
                }
            }
        }
        return s.substr(start, maxlen); 
    }

    bool isPalindrome(string &s, int i, int j, vector<vector<int>>&dp){
        if(i>j) return true; 
        if(dp[i][j]!=-1) return dp[i][j];    
        if(s[i]!=s[j]) return dp[i][j]=false;
        return dp[i][j]= isPalindrome(s,i+1, j-1, dp);  
    }
};   