class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size(); 
        vector<pair<int,int>>time; 
        for(int i=0; i<n; i++){
            int dist=target-position[i]; 
            int sp= speed[i];
            time.push_back({dist,sp});
        }
        sort(time.rbegin(), time.rend()); 
        double curr=-1; int fleet=1; 

        for(int i=n-1; i>=0; i--){
            double realtime= (double) (time[i].first)/time[i].second; 
            if(curr==-1){
                curr=realtime; 
            }
            else if(curr!=-1 && realtime>curr){
                fleet++; 
                curr=realtime; 
            }
        }
    return fleet; 
    }
};