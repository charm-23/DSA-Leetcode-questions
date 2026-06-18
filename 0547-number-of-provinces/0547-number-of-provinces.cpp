class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size(); 
        vector<int>visited(n,0);
        int province=0; 
        for(int i=0; i<n; i++){
            if(!visited[i]){
                province++; 
                dfs(i,isConnected,visited,n);  
            }
        }
    return province; 
    }

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>&visited, int n){
        visited[node]=1; 
        for(int k=0; k<n; k++){
            if(isConnected[node][k]==1 && !visited[k]){
                dfs(k, isConnected, visited, n); 
            }
        }
    }
};