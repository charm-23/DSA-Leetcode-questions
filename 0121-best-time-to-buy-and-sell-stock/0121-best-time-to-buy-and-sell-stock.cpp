class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //track min so far
        int maxprof=0; 
        int mini= prices[0]; 
        for(int i=1; i<prices.size(); i++){
            int cost= prices[i]- mini; 
            mini=min(mini, prices[i]);
            maxprof= max(maxprof, cost); 
        }
    return maxprof; 
       
    }
};