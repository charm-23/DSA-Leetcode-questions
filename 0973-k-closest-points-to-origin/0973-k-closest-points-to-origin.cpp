class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans; 
        priority_queue<pair<int, vector<int>>> maxh; 
        
        for(auto it: points){
            maxh.push({(pow(it[0],2) + pow(it[1],2)), it}); 
            while(maxh.size()>k){
                maxh.pop(); 
            }
        }

        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop(); 
        }
    return ans;
        
    }
};