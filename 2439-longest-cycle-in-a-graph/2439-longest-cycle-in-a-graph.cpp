class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>visited(n,0);
        vector<int>curr_path(n,0);
        int maxcycle=-1; 

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, edges, curr_path, visited, n,1, maxcycle);
            }
        }
        return maxcycle;
    }
    
    void dfs(int node,vector<int>& edges, vector<int>&curr_path, vector<int>&visited, int n, int cyclen, int &maxcycle){
        visited[node]=1; 
        curr_path[node]=cyclen;

        if(edges[node]!=-1){
            if(!visited[edges[node]]){
                dfs(edges[node], edges, curr_path, visited, n, cyclen+1, maxcycle); {
            
                }
            }
            else if(curr_path[edges[node]]!=0){
                int currentlength= curr_path[node]-curr_path[edges[node]]+1;
                maxcycle= max(maxcycle, currentlength);
            }
        }
        curr_path[node]=0;
         
    }
};