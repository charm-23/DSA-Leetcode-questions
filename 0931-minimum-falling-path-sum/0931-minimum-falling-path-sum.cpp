class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(); 
        int ans=INT_MAX; 
        for(int i=0; i<n; i++){
            vector<vector<int>>dp(n, vector<int>(n,INT_MAX)); 
            ans=min(ans, helper(0,i,n,matrix,dp)); 
        }
        return ans; 
    }

    int helper(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(i==n) return INT_MAX; 

        if(dp[i][j]!=INT_MAX) return dp[i][j]; 

        long long sum=matrix[i][j]; 
        int diagonalleft=INT_MAX; int diagonalright=INT_MAX; int below=INT_MAX; 

        if(i+1<n){ 
            below= helper(i+1,j, n, matrix,dp);  
        }
        if(i+1<n && j+1<n){
            diagonalright=helper(i+1, j+1, n, matrix,dp); 
        }
        if(i+1<n && j-1>=0){
            diagonalleft=helper(i+1, j-1, n, matrix,dp);
        }

        if(min(diagonalright, min(below, diagonalleft))== INT_MAX) return sum; 

        return dp[i][j]= (int)(sum+ min(diagonalright, min(below, diagonalleft)));  
    }
};