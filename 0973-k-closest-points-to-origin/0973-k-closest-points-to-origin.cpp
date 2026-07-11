class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans; 
        priority_queue<pair<int, vector<int>>>maxh; 

        for(auto &i: points){
            int x=i[0]; 
            int y=i[1]; 
            int dist= pow(x,2)+ pow(y,2); 
            maxh.push({dist, i}); 
        }

        while(maxh.size()>k){
            maxh.pop(); 
        }

        while(!maxh.empty()){
            ans.push_back(maxh.top().second); 
            maxh.pop(); 
        }

        return ans; 
    }
};