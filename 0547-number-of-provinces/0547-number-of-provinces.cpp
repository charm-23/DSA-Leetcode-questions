class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size(); 
        vector<int>visited(n,0);
        int province=0; 
        for(int i=0; i<n; i++){
            if(!visited[i]){
                province++; 
                bfs(i,isConnected,visited,n);  
            }
        }
    return province; 
    }

    void bfs(int node, vector<vector<int>>&isConnected, vector<int>&visited, int n){
        visited[node]=1;
        queue<int>q; 
        q.push(node); 

        while(!q.empty()){
            int num=q.front(); 
            q.pop();

            for(int k=0; k<n; k++){
                if(isConnected[num][k]==1 && !visited[k]){
                    visited[k]=1; 
                    q.push(k);
                }

            }
        }
    }
};