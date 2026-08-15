class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(); 
        int m= grid[0].size(); 

        queue<pair<int, int>>q; 

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j}); 
                }
            }
        }

        int minutes=-1; 
        int dx[]={-1,1,0,0}; 
        int dy[]={0,0,1,-1}; 

        while(!q.empty()){
            int size= q.size(); 
            
            for(int i=0; i<size; i++){
                int x= q.front().first; 
                int y= q.front().second; 
                q.pop(); 

                for(int k=0; k<4; k++){
                    int nx= x+ dx[k]; 
                    int ny= y+ dy[k]; 

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2; 
                        q.push({nx, ny}); 
                    }
                }
            }
            minutes++; 
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) return -1; 
            }
        }

        return (minutes==-1? 0: minutes); 
    }
};