class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size(); 

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; 

        int maxele= INT_MIN; 

        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0}); 
            maxele= max(maxele, nums[i][0]); 
        }

        vector<int>range= {-1000000, 1000000}; 

        while(!pq.empty()){
            vector<int>curr= pq.top(); 
            pq.pop(); 

            int minele = curr[0]; 
            int listidx= curr[1]; 
            int idx= curr[2]; 

            if(maxele- minele< range[1]-range[0]){
                range[0]= minele; 
                range[1]= maxele; 
            }

            if(idx+1< nums[listidx].size()){
                int nextele= nums[listidx][idx+1]; 
                pq.push({nextele, listidx, idx+1}); 
                maxele= max(maxele, nextele); 
            }
            else{
                break; 
            }
        }
        return range; 
    }
};