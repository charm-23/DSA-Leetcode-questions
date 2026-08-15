class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0); 
        unordered_map<int, vector<int>>neighbours; 

        for(auto&i: prerequisites){
            int a=i[0]; int b=i[1]; 
            indegree[a]++; 
            neighbours[b].push_back(a);
        } 

        queue<int>q; 

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i); 
        }

        while(!q.empty()){
            int x=q.front(); 
            q.pop(); 

            for(int i: neighbours[x]){
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