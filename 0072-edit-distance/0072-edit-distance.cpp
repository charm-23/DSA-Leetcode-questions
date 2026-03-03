class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(); 
        int m= word2.size(); 
        vector<vector<int>>dp (n+1, vector<int>(m+1,-1));
        return helper(word1, word2, n, m, dp);
    }

    int helper(string word1, string word2, int i, int j, vector<vector<int>>&dp){ 
        if(i==0 && j==0) return 0; 
        else if(i==0) return j; // insert
        else if(j==0) return i; // delete 

        if(dp[i][j]!= -1) return dp[i][j]; 

        else{
            if(word1[i-1]== word2[j-1]){
                return dp[i][j]= helper(word1, word2, i-1, j-1,dp);
            }
            else{
                int deleteo= 1+ helper(word1, word2, i-1, j,dp);  
                int replace= 1+ helper(word1, word2, i-1, j-1,dp);  
                int insert= 1+ helper(word1, word2, i, j-1,dp); 

                return dp[i][j]= min(insert,min(deleteo, replace)); 
            }
        }
    }
};