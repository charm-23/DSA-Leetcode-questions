class Solution {
public:
    //Djkshtra's algorithm with min heap 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>>adjlist; 

        for(auto &i: times){
            int a= i[0]; 
            int b= i[1]; 
            int time= i[2]; 

            adjlist[a].push_back({time, b});  
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minh; // (dist,node)
        vector<int>dist(n+1,1e9); 
        dist[k]=0; 

        minh.push({0,k}); 

        while(!minh.empty()){
            int node= minh.top().second; 
            int nodedist= minh.top().first; 
            minh.pop(); 

            for(auto& ngbr : adjlist[node]){
                if(nodedist+ ngbr.first< dist[ngbr.second]){
                    dist[ngbr.second]= nodedist+ ngbr.first; 
                    minh.push({dist[ngbr.second], ngbr.second}); 
                }
            }
        }

        int ans=-1; 
        for(int i=1; i<n+1; i++){
            if(dist[i]==1e9) return -1; 
            else{
                ans= max(ans, dist[i]); 
            }
        }

    return ans; 
    }
};