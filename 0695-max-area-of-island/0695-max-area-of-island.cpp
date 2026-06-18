class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(); 
        int n= grid[0].size(); 
        vector<vector<int>>visited(m, vector<int>(n,0)); 
        int maxarea=0; 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=0; 
                    bfs(grid, visited, i, j, area, m, n); 
                    maxarea= max(maxarea,area); 
                }
            }
        }
        return maxarea; 
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>&visited, int i, int j, int &area, int m, int n){
        visited[i][j]=1;
        queue<pair<int, int>>q; 
        q.push({i, j});

        while(!q.empty()){
            int row=q.front().first; 
            int col= q.front().second; 
            area++; 
            q.pop(); 

            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1}; 
        
            for(int k=0; k<4; k++){
                int nrow= row+ dx[k];
                int ncol= col+ dy[k]; 

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    q.push({nrow, ncol}); 
                }
            }
        } 
    }
};