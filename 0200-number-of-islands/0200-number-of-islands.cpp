class Solution {
public:
//BFS CODE 
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        vector<vector<int>>visited(n, vector<int>(m,0)); 
        int cnt=0; 
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    bfs(row,col,grid, visited, n, m);
                    cnt++; 
                }
            }
        }
    return cnt; 
    }

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>&visited, int n, int m){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});  

        while(!q.empty()){
            int row= q.front().first; 
            int col= q.front().second;
            q.pop();

            int dx[]={-1,1,0,0}; 
            int dy[]={0,0,1,-1};

            for(int i=0; i<4; i++){
                int nrow= row+ dx[i]; 
                int ncol= col+ dy[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow, ncol}); 
                    visited[nrow][ncol]=1; 
                }
            }
        } 
    }

};