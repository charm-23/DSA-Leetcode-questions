class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(); int m= matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1)); 
        int maxlen=1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxlen= max(helper(i, j, matrix, n, m,dp), maxlen); 
            }
        }
        return maxlen; 
    }


    int helper(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>&dp){

        if(dp[i][j]!=-1) return dp[i][j]; 

        int dx[]={-1,1,0,0}; 
        int dy[]={0,0,1,-1};
       
        int len=1; 
        for(int k=0; k<4; k++){
            int nr= i+dx[k]; 
            int nc= j+dy[k]; 

            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[i][j]){
                len= max(len, 1+ helper(nr, nc, matrix, n, m, dp)); 
            }
        }
        return dp[i][j]= len; 
    }
};