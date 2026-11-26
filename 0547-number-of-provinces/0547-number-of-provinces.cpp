class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(); 
        vector<int>visited(n, 0); 

        int provinces=0; 

        for(int i=0; i<n; i++){
            if(!visited[i]){
                provinces++; 
                dfs(i, isConnected, visited); 
            }
        }

        return provinces; 
    }

    // void bfs(int node, vector<vector<int>>& isConnected, vector<int>&visited){
    //     queue<int>q; 
    //     q.push({node}); 
    //     visited[node]=1; 

    //     while(!q.empty()){
    //         int node= q.front(); 
    //         q.pop(); 

    //         for(int k=0; k<isConnected.size(); k++){
    //             if(isConnected[node][k]==1 && !visited[k]){
    //                 visited[k]=1; 
    //                 q.push(k); 
    //             }
    //         }
    //     }
    // }


    void dfs(int node, vector<vector<int>>& isConnected, vector<int>&visited){
        visited[node]=1; 

        for(int k=0; k<isConnected.size(); k++){
            if(!visited[k] && isConnected[node][k]==1){
                dfs(k, isConnected, visited); 
            }
        }
    }
};