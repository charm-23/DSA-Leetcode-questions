class Solution {
public:
    int uniquePaths(int m, int n){
        vector<int>row(n,1);
        for(int i=1; i<m; i++){
            vector<int>newrow(n,1); 
            for(int j=1; j<n; j++){
                newrow[j]= newrow[j-1]+ row[j]; 
            }
            row=newrow; 
        }
        return row[n-1]; 
    }

    // int helper(int i, int j, int m, int n, vector<vector<int>>&dp){
    //     if(i==m-1 && j==n-1) return 1; 
    //     if(i==m || j==n) return 0; 

    //     if(dp[i][j]!=-1) return dp[i][j]; 

    //     int down=0; int right=0; 
    //     if(i+1<m){
    //         down= helper(i+1, j, m, n,dp); 
    //     }

    //     if(j+1<n){
    //         right= helper(i, j+1, m, n,dp); 
    //     }
    //     return dp[i][j]=down+right; 
    // }
};