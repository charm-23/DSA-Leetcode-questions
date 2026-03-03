class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(); 
        int m= p.size(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return helper(s,p,n,m,dp); 
    }
    bool helper(string &s, string &p, int i, int j,vector<vector<int>>&dp){ 
        if(i==0 && j==0) return true; 
        if(j==0) return false;
        if(i==0){
            for(int k=0; k<j; k++){
                if(p[k]!='*') return false; 
            }
            return true; 
        } 

        if(dp[i][j]!=-1) return dp[i][j]; 

        else{ 
            if(s[i-1]==p[j-1]){
                return dp[i][j]= helper(s, p, i-1, j-1,dp); 
            }
            else{
                if(p[j-1]=='?'){
                    return dp[i][j]=helper(s,p, i-1, j-1,dp); 
                }
                else if(p[j-1]=='*'){
                    return dp[i][j]= helper(s,p, i, j-1,dp) || helper(s,p,i-1,j,dp); 
                }      
                else{
                    return dp[i][j]= false; 
                }
            }
        }
    }
};