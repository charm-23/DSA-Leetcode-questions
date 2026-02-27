class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2= s; 
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s2.size()+1, -1)); 
        return lcs(s, s2, s.size(), s2.size(), dp);
    }

    int lcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp){ 
        if(n==0 || m==0) return 0; 

        if(dp[n][m]!=-1){
            return dp[n][m]; 
        }

        else if(s1[n-1]== s2[m-1]){ 
            return dp[n][m]= 1+ lcs(s1, s2, n-1, m-1, dp); 
        }

        else{
            return dp[n][m]= max(lcs(s1, s2, n, m-1, dp), lcs(s1, s2, n-1, m, dp)); 
        }
    }
};