class Solution {
public:
//DFS CODE 
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        vector<vector<int>>visited(n, vector<int>(m,0)); 
        int cnt=0; 
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    dfs(row,col,grid, visited, n, m);
                    cnt++; 
                }
            }
        }
    return cnt; 
    }

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&visited, int n, int m){
        visited[row][col]=1;

        int dx[]= {-1,1,0,0};
        int dy[]= {0,0,1,-1};

        for(int i=0; i<4; i++){
            int nr= row+ dx[i]; int nc= col+ dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]=='1'){
                visited[nr][nc]=1; 
                dfs(nr, nc, grid, visited, n, m);
            }
        }
    }

};