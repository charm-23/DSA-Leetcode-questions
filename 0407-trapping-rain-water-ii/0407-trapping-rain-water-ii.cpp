class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows= heightMap.size(); int cols= heightMap[0].size(); 
        vector<vector<bool>>visited(rows, vector<bool>(cols, false)); 

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1}; 

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq; 

        for(int i=0; i<cols; i++){
            pq.push({heightMap[0][i], {0, i}}); 
            visited[0][i]= true; 
            pq.push({heightMap[rows-1][i], {rows-1, i}}); 
            visited[rows-1][i]= true; 
        }

        for(int i=0; i<rows; i++){
            pq.push({heightMap[i][0], {i, 0}}); 
            visited[i][0]= true; 
            pq.push({heightMap[i][cols-1], {i, cols-1}}); 
            visited[i][cols-1]= true; 
        }

        int water=0; 

        while(!pq.empty()){
            int height= pq.top().first; 
            int i= pq.top().second.first; 
            int j= pq.top().second.second; 

            pq.pop();

            for(int k=0; k<4; k++){
                int i_= i+ dx[k]; 
                int j_= j+ dy[k]; 

                if(i_>=0 && i_<rows && j_>=0 && j_<cols && !visited[i_][j_]){
                    water+= max(height-heightMap[i_][j_], 0); 

                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}}); 

                    visited[i_][j_]= true;

                }

            }
        }
        return water; 
    }
};