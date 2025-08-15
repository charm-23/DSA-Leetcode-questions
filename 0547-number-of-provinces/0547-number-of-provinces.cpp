class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        unordered_map<int, vector<int>> adjlist; 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j) adjlist[i].push_back(j);
            }
        }

        int provinces=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                provinces++;
                bfs(visited, adjlist, i);
            }
        }
        return provinces;
    }

    void bfs(vector<int>&visited, unordered_map <int, vector<int>> &adjlist, int node){
        queue<int>q; 
        visited[node]=1; 
        q.push(node); 

        while(!q.empty()){
            int curr= q.front(); 
            q.pop(); 

            for(int ngbr: adjlist[curr]){
                if(!visited[ngbr]){
                    visited[ngbr]=1;
                    
                    q.push(ngbr);
                }
            }
        }
    }
};