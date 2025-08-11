class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size(); 
        vector<int>ans; 
        vector<int>visited(n,0);
        vector<int>curr_path(n,0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, graph, ans, visited, curr_path);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>&ans,vector<int>&visited, vector<int>&curr_path){
        visited[node]=1; 
        curr_path[node]=1; 

        for(int ngbr: graph[node]){
            if(!visited[ngbr]){
                if(!dfs(ngbr, graph,ans, visited, curr_path)){
                    return false; 
                }
            }

            else if(visited[ngbr]==1 && curr_path[ngbr]==1){
                return false;
            }
        }

        curr_path[node]=0; 
        ans.push_back(node);
        return true;
    }
};