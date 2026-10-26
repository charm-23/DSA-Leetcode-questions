class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0); 
        unordered_map<int, vector<int>>adjlist; 

        queue<int>q; 

        for(auto &i: prerequisites){
            int a= i[0]; 
            int b= i[1]; 
            adjlist[b].push_back(a); 
            indegree[a]++; 
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i); 
        }

        while(!q.empty()){
            int node=q.front(); 
            q.pop(); 

            for(int i: adjlist[node]){
                indegree[i]--; 
                if(indegree[i]==0) q.push(i); 
            }
        }

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]!=0) return false; 
        }

        return true; 
    }
};