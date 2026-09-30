class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>>pq; 
        priority_queue<int, vector<int>, greater<int>>availablerooms; 

        sort(meetings.begin(), meetings.end()); 

        vector<int>mpp(n,0); 

        for(int i=0; i<n; i++){
            availablerooms.push(i); 
        }

        int i=0; 

        while(i<meetings.size()){
            long long start=meetings[i][0]; 
            long long end=meetings[i][1]; 

            while(!pq.empty() && pq.top().first<=start){
                auto[endtime, room]=pq.top(); 
                pq.pop(); 

                availablerooms.push(room); 
            }

            if(!availablerooms.empty()){
                pq.push({end, availablerooms.top()}); 
                mpp[availablerooms.top()]++; 
                availablerooms.pop(); 
            }

            else{
                auto[endtime, room]=pq.top();
                pq.pop(); 

                long long offset=endtime-start; 
                long long newend=end+offset; 

                pq.push({newend, room});
                mpp[room]++; 

            }

            i++; 
        }

        int maxi=0; 
        int ans=-1; 

        for(int i=n-1; i>=0; i--){
            if(mpp[i]>=maxi){
                ans=i; 
                maxi=mpp[i]; 
            }
        }
        return ans;
    }
};
