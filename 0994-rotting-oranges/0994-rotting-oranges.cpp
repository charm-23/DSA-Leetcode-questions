class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(); 
        int n=grid[0].size(); 

        int dx[]={-1, 0, 1, 0};
        int dy[]={0, 1, 0, -1}; 

        queue<pair<int,int>>q; 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i, j}); 
            }
        }

        int minutes=0; 

        while(!q.empty()){
            int size=q.size(); 

            for(int i=0; i<size; i++){
                int x=q.front().first; 
                int y=q.front().second; 

                q.pop();

                for(int k=0; k<4; k++){
                    int nx= x+ dx[k];
                    int ny=y+ dy[k]; 

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2; 
                        q.push({nx, ny}); 
                    }
                }
            }
            minutes++; 
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) return -1; 
            }
        }

        return minutes==0? -1: minutes-1; 
    }
};