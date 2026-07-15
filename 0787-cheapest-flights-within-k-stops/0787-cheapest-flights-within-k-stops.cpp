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

        vector<int>dist(n+1, 1e9); 

        queue<pair<int,int>>q; 
        q.push({0,src}); 
        int steps=0; 
        int ans= 1e9; 

        while(!q.empty() && steps<=k+1){
            int size= q.size();

            for(int i=0; i<size; i++){
                int node= q.front().second; 
                int price= q.front().first; 

                if(node==dst){
                    ans= min(ans, price); 
                }

                q.pop(); 

                for(auto& ngbr: adjlist[node]){
                    if(price+ ngbr.first < dist[ngbr.second]){
                        dist[ngbr.second]= price+ ngbr.first; 
                        q.push({price+ ngbr.first, ngbr.second}); 
                    }
                }

            }
            steps++;
        }
        return ans==1e9? -1: ans ; 
    }
}; 
