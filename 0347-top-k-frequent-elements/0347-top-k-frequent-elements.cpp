class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp; 
        for(int i:nums){
            mpp[i]++; 
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; 

        for(auto &p: mpp){
            int i= p.first; 
            int j= p.second; 

            pq.push({j,i});

            if(pq.size()>k){
                pq.pop(); 
            }
        }

        vector<int>ans; 
        while(!pq.empty()){
            ans.push_back(pq.top().second); 
            pq.pop(); 
        }

        return ans; 
    }
};