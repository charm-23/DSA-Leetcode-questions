class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        vector<int>suffix(n, 0); 
        int maxi=prices[n-1]; 
        int ans=0; 
        for(int i=n-2; i>=0; i--){
            suffix[i]=maxi; 
            ans= max(suffix[i]-prices[i],ans); 
            maxi= max(maxi, prices[i]); 
        }
        return ans; 
    }
};