class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq; 
        int maxval=INT_MIN; 
        pq.push({points[0][1]-points[0][0], points[0][0]}); 

        for(int j=1; j<points.size(); j++){
            int xj=points[j][0]; int yj=points[j][1];

            while(!pq.empty() && xj-pq.top().second>k){
                pq.pop(); 
            }
            
            if(!pq.empty()){
                maxval=max(maxval, yj+ xj + pq.top().first); 
            }

            pq.push({yj-xj,xj});
        }
        return maxval; 
    }
};