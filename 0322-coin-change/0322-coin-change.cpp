class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size(); 
        vector<int>prev(amount+1, INT_MAX), curr(amount+1, INT_MAX);  

        for(int i=0; i<n; i++){
            prev[0]=0; 
        }
        curr[0]=0; 

        for(int i=1; i<=amount; i++){
            if((i%coins[0])==0) prev[i]=i/coins[0]; 
        }

        for(int i=1; i<n; i++){
            for(int sum=1; sum<=amount; sum++){
                int nottake=prev[sum]; 

                int take=INT_MAX; 
                if(coins[i]<=sum && curr[sum-coins[i]]!=INT_MAX) take= 1+ curr[sum-coins[i]]; 

                curr[sum]= min(take, nottake); 
            }
            prev=curr; 
        }

        return prev[amount]==INT_MAX? -1: prev[amount]; 
    }
};