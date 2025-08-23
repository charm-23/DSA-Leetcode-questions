class Solution {
public:     
    int orangesRotting(vector<vector<int>>& grid) {
        int rows= grid.size(); 
        int cols= grid[0].size(); 
        queue<pair<int, int>> q; 
        vector<vector<int>>visited(rows, vector<int>(cols,0)); 
        vector<int> dx= {1,-1,0,0}; 
        vector<int>dy= {0,0,1,-1}; 
        int minutes=-1; 

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(!visited[i][j] && grid[i][j]==2){
                    visited[i][j]=1; 
                    q.push({i,j});
                }
            }
        }

         bfs(grid,q, visited, rows, cols, minutes, dx, dy);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    return -1; 
                }
            }
        }

        return (minutes==-1? 0: minutes); 
       
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>> &q, vector<vector<int>>& visited, int rows, int cols, int &minutes, vector<int>dx,vector<int>dy){

        while(!q.empty()){

            int size= q.size(); 

            for(int i=0; i<size; i++){
                int n1= q.front().first; 
                int n2= q.front().second; 

                q.pop();

                for(int k=0; k<4; k++){
                 int ni= n1+ dx[k]; 
                 int nj= n2+ dy[k];

                if(ni>=0 && ni<rows && nj>=0 && nj<cols && !visited[ni][nj] && grid[ni][nj]==1){
                    visited[ni][nj]=1; 
                    grid[ni][nj]=2; 
                    q.push({ni,nj}); 
                   }
                }

            }

            minutes++; 
        }
    }
};