class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(); 
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n, -1))); 
        return max(0, helper(0, 0, 0, n,grid,  dp)); 
    }

    int helper(int r1, int c1, int c2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
        int r2= r1+ c1-c2; 
        if(r1>=n || r2>=n || c1>=n || c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1) return -1e9; 
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2]; 

        if(r1==n-1 && c1==n-1) return grid[r1][c1]; 

        int ans= grid[r1][c1]; 
        if(r1!=r2 || c1!=c2) ans+= grid[r2][c2]; 

        int temp= max(helper(r1, c1+1, c2+1, n, grid, dp), helper(r1+1, c1, c2, n,grid, dp)); 
        temp= max(temp, helper(r1+1, c1, c2+1, n, grid, dp)); 
        temp= max(temp, helper(r1, c1+1, c2, n, grid, dp)); 

        if(temp==-1e9){
            ans= -1e9; 
        }
        else ans+=temp; 
        

        return dp[r1][c1][c2]=ans; 
    }
};