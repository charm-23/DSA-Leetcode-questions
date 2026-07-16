class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int dx[]={-1,1,0,0}; 
        int dy[]={0,0,1,-1}; 
        vector<vector<int>> visited(n, vector<int>(n,0)); 

        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>minh; 

        minh.push({grid[0][0], {0,0}}); 
        int maxtimesofar=INT_MIN; 

        while(!minh.empty()){
            int x=minh.top().second.first; 
            int y=minh.top().second.second; 

            maxtimesofar= max(maxtimesofar, minh.top().first); 

            minh.pop(); 

            if(x==n-1 && y==n-1){
                return  maxtimesofar; 
            }

            for(int k=0; k<4; k++){
                int nx= x+ dx[k]; 
                int ny= y+ dy[k]; 

                if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]==0){
                    visited[nx][ny]=1; 
                    minh.push({grid[nx][ny], {nx, ny}}); 
                }
            }
        }
        return maxtimesofar; 
    }
};