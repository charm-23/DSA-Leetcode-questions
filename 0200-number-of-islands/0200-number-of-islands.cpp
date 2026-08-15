class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m= grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0)); 
        int island=0; 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    bfs(i, j, n, m, grid,visited);
                    island++; 
                }
            }
        }
        return island; 
    }

    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>&visited){
        queue<pair<int,int>>q; 
        q.push({i,j}); 
        int dx[]={-1,0,1,0}; 
        int dy[]={0,1,0,-1}; 

        while(!q.empty()){
            int x= q.front().first; 
            int y= q.front().second; 
            q.pop(); 

            for(int k=0; k<4; k++){
                int nx= x+ dx[k]; 
                int ny= y+ dy[k]; 

                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]=='1'){
                    visited[nx][ny]=1;
                    q.push({nx, ny}); 
                }
            }
        }
    }
};