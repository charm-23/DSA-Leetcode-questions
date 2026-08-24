class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,INT_MAX)); 
        return helper(0,0,n, triangle,dp);  
    }

    int helper(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        if(i==n) return INT_MAX; 

        if(dp[i][j]!=INT_MAX) return dp[i][j]; 

        int option1= helper(i+1, j, n, triangle,dp); 
        int option2= helper(i+1, j+1, n, triangle,dp); 

        if(min(option1, option2)==INT_MAX) return dp[i][j]= triangle[i][j]; 

        return dp[i][j]=triangle[i][j]+ min(option1, option2); 
    }

};