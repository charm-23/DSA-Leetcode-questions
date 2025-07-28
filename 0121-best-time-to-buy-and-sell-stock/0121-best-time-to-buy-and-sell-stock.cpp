class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice= prices[0];     
        int maxprofit=0; 

        for(int i=1; i<prices.size(); i++){
            int profit= prices[i]-minPrice; 
            maxprofit= max(profit, maxprofit);

            minPrice= min(prices[i], minPrice);
        } 
    return maxprofit; 
    }
};