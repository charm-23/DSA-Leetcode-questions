class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<int, vector<int>>mpp; 

        for(int i=0; i<parent.size(); i++){
            mpp[parent[i]].push_back(i); 
        }

        vector<int>heights(parent.size()); 

        queue<int>q; 
        q.push(0); 
        int height=1;  

        while(!q.empty()){
            int size= q.size(); 
            
            for(int i=0; i<size; i++){
                int node=q.front(); 
                heights[node]=height;
                q.pop(); 

                for(int ngbr:mpp[node]){
                    q.push(ngbr); 
                }
            }
            height++; 
        }

        int depth= height-1; 
        long long sum=0; 

        for(int i=0; i<parent.size(); i++){
            sum+= 1LL*nums[i]*(depth-heights[i]+1); 
        }

    return sum; 
    }
};