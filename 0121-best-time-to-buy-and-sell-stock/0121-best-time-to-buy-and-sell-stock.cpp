class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0; 
        int i=prices.size()-2; int j=prices.size()-1; 
        int maxj= 0; int ans=0;
        for(int i=prices.size()-2; i>=0; i--){
            maxj=max(maxj, prices[j]); 
            ans=max(ans, maxj-prices[i]); 
            j--; 
        }
        return ans<0? -1: ans; 
    }
};