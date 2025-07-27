class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,0); 
        unordered_map <int,vector<int>> graph;
        for(int i=0;i< edges.size(); i++){
            int a= edges[i][0];
            int b= edges[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        return dfs(graph, n, source, destination, visited); 
    }

    bool dfs(unordered_map <int,vector<int>>&graph,int n, int node, int destination, vector<int> &visited){
        if(node== destination){
            return true; 
        }

        visited[node]=1; 

        for(int ngbr: graph[node]){
            if(!visited[ngbr]){
                if(dfs(graph, n, ngbr ,destination,visited)) return true;
            }
            
        }
    return false;
    }
};