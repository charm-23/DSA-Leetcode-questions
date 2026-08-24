class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size(); 
        int n= obstacleGrid[0].size(); 
        vector<vector<int>>dp(m, vector<int>(n,-1)); 
        return helper(0,0,m,n,obstacleGrid, dp); 
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
        if(!obstacleGrid[i][j] && i==m-1 && j==n-1) return 1; 

        if(obstacleGrid[i][j]) return 0; 

        if(dp[i][j]!=-1) return dp[i][j]; 

        int right=0; int down=0; 

        if(i+1<m) down= helper(i+1, j, m, n, obstacleGrid,dp); 
        if(j+1<n) right= helper(i, j+1, m, n, obstacleGrid,dp);

        return dp[i][j]=down+right; 
    }
};