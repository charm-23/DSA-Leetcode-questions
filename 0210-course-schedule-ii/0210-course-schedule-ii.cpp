class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans; 
        vector<int>indegree(numCourses,0);
        unordered_map<int, vector<int>>adjlist; 

        for(auto &i: prerequisites){
            int a=i[0]; 
            int b=i[1];

            adjlist[b].push_back(a); 
            indegree[a]++; 
        }

        queue<int>q; 
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i); 
        }

        while(!q.empty()){
            int course=q.front(); 
            q.pop(); 
            ans.push_back(course); 

            for(int ngbr: adjlist[course]){
                indegree[ngbr]--; 
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i]!=0) return {};
        }
    return ans;
    }
};