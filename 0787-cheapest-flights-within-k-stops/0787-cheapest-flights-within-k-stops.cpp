class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>>adjlist; 

        for(auto &i: flights){
            int u= i[0]; 
            int v= i[1]; 
            int price= i[2]; 

            adjlist[u].push_back({price, v}); 
        }
        vector<int>dist(n,INT_MAX);

        //BFS --> K+1 levels 

        queue<pair<int, int>>q; 
        q.push({0, src}); 
        int level=0; 
        int ans=INT_MAX; 

        while(!q.empty() && level<=k+1){
            int size= q.size();

            for(int i=0; i<size; i++){
                int node= q.front().second; 
                int price= q.front().first; 

                if(node==dst){ 
                    ans= min(ans, price); 
                }
                q.pop(); 

                for(auto &ngbr: adjlist[node]){
                    int ngbrprice=ngbr.first; 
                    int flight= ngbr.second; 
                    
                    if (price + ngbrprice < dist[flight]) {
                        dist[flight] = price + ngbrprice;
                        q.push({dist[flight], flight}); 
                    }
                }
            }
            level++; 
        }

        return ans==INT_MAX? -1: ans; 
    }
};