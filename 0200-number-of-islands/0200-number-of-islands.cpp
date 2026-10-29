class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 


        int islands=0; 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    islands++; 
                    dfs(i, j, n, m, grid); 
                }
            }
        }

        return islands;
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        grid[i][j]='0'; 
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1}; 

        for(int k=0; k<4; k++){
            int nx= i+ dx[k]; 
            int ny= j+ dy[k]; 

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1'){
                dfs(nx, ny, n, m, grid); 
            }
        }
    }
};