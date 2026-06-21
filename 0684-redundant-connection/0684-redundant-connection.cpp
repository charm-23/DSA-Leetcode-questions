class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size(); 
        unordered_map<int, vector<int>>adjlist; 

        for(auto &i: edges){
            if(adjlist.find(i[0])!= adjlist.end() && adjlist.find(i[1])!= adjlist.end()){
                vector<int>visited(n+1,0); 
                if(dfs(i[0], i[1], visited, adjlist, n)) return {i[0], i[1]}; 
            }
            int a=i[0]; 
            int b=i[1]; 

            adjlist[a].push_back(b); 
            adjlist[b].push_back(a); 
        }
    return {}; 
    }


    bool dfs(int node1, int node2, vector<int>&visited,  unordered_map<int, vector<int>>&adjlist,int n){
        visited[node1]=1; 

        for(int ngbr: adjlist[node1]){
            if(ngbr==node2) return true; 
            if(!visited[ngbr]){
                if(dfs(ngbr, node2,visited, adjlist, n)) return true;
            }
        }
    return false; 
    }
};