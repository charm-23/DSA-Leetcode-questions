// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> indegree(numCourses, 0);
        
//         unordered_map<int, vector<int>>adjlist; 
        
//         for(int i=0; i<prerequisites.size(); i++){
//             int a= prerequisites[i][0]; 
//             int b= prerequisites[i][1];
            
//             adjlist[a].push_back(b);
//             indegree[b]++;
//         }

//         return cycle(indegree, prerequisites, adjlist, numCourses);
//     }

//     bool cycle(vector<int>& indegree, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>adjlist, int numCourses){
//         queue<int> q;
//         vector<int>ans; 

//         for(int i=0; i<numCourses; i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }

//         while(!q.empty()){
//             int node= q.front();
//             q.pop(); 
//             ans.push_back(node);

//             for(int ngbr: adjlist[node]){
//                 indegree[ngbr]--; 

//                 if(indegree[ngbr]==0) q.push(ngbr);
//             }
//         }

//         if(ans.size()!= numCourses){
//             return false;
//         }
//         else{
//             return true;
//         }
//     }

// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        
        unordered_map<int, vector<int>>adjlist; 
        
        for(int i=0; i<prerequisites.size(); i++){
            int a= prerequisites[i][0]; 
            int b= prerequisites[i][1];
            
            adjlist[a].push_back(b);
            indegree[b]++;
        }

        cycle(indegree, prerequisites, adjlist, numCourses);

        for(int i: indegree){
            if(i!=0){
                return false;
            }
        }

        return true; 

    }

    void cycle(vector<int>& indegree, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>& adjlist, int numCourses){
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop(); 

            for(int ngbr: adjlist[node]){
                indegree[ngbr]--; 

                if(indegree[ngbr]==0) q.push(ngbr);
            }
        }
    }

};