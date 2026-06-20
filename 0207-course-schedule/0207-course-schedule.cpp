class Solution {
public:
//topological sort/ cycle detection in BFS using KHAN'S ALGO 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adjlist;
        vector<int>indegree(numCourses,0); 

        for(auto &i: prerequisites){
            int a= i[0];    
            int b= i[1];

            adjlist[b].push_back(a);
            indegree[a]++;  
        }

        queue<int>q; 
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i); 
            }
        }

        while(!q.empty()){
            int course=q.front(); 
            q.pop(); 

            for(int ngbr: adjlist[course]){
                indegree[ngbr]--; 
                if(indegree[ngbr]==0){ 
                    q.push(ngbr); 
                }
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]!=0) return false; 
        }

    return true; 
    }
};