class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m= grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0)); 
        int ans=0; 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    ans= max(ans,dfs(i, j, n, m, grid,visited));
                }
            }
        }
        return ans; 
    }

    int dfs(int i, int j, int n, int m,vector<vector<int>>& grid, vector<vector<int>>&visited){
        visited[i][j]=1;
        int area=1; 
        int dx[]={-1,1,0,0}; 
        int dy[]={0,0,-1,1}; 

        for(int k=0; k<4; k++){
            int nx=i+ dx[k]; 
            int ny=j+ dy[k]; 

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && !visited[nx][ny]){
                area= area+ dfs(nx, ny,n, m , grid, visited); 

            }
        }
        return area; 
    }
};