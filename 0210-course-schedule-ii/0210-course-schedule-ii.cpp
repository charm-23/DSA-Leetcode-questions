class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int>ans; 
        vector<int> curr_path(numCourses,0);

        unordered_map<int,vector<int>>adjlist; 

        for(int i=0; i<prerequisites.size(); i++){
            int a= prerequisites[i][0];
            int b= prerequisites[i][1];

            adjlist[b].push_back(a); 
        
        }

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(!dfs(i, visited, adjlist, ans, curr_path)) return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }

    bool dfs(int node, vector<int>& visited, unordered_map<int,vector<int>> &adjlist, vector<int>& ans, vector<int> & curr_path){
        visited[node]=1; 
        curr_path[node]=1;

        for(int ngbr: adjlist[node]){
            if(!visited[ngbr]){
                if(!dfs(ngbr, visited, adjlist, ans, curr_path)) return false;
            }

            else if(visited[ngbr] && curr_path[ngbr]==1) return false;
        }
        
        curr_path[node]=0;
        ans.push_back(node);
        return true; 
    }
};


// dfs+ backtracking (curr_path) for checking cycles.

// bfs + ans.size()==numCourses/ indegree[nodes]==0 for cycles 