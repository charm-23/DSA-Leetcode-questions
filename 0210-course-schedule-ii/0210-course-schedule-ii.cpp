class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans; 
        unordered_map<int, vector<int>>mpp; 
        vector<int>indegree(numCourses,0); 

        for(auto &i: prerequisites){
            int a=i[0]; int b=i[1]; 
            indegree[a]++; 
            mpp[b].push_back(a); 
        }

        queue<int>q; 

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) q.push(i); 
        }

        while(!q.empty()){
            int x=q.front(); 
            ans.push_back(x);
            q.pop(); 

            for(int i: mpp[x]){
                indegree[i]--; 
                if(indegree[i]==0) q.push(i); 
            }
        }

        if(ans.size()!=numCourses) return {}; 
        return ans; 
    }
};