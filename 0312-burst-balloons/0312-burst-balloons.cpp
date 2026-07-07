class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size(); 
        vector<vector<int>>dp(n+2, vector<int>(n+2,-1)); 
        vector<int>balloons(n+2,1); 
        for(int i=0; i<nums.size(); i++){
            balloons[i+1]= nums[i]; 
        }

        return helper(1, n, balloons, dp); 
    }

        int helper(int i, int j, vector<int>&balloons, vector<vector<int>>&dp){
            if(i>j) return 0; 

            if(dp[i][j]!=-1) return dp[i][j];

            int maxcoins=0; 

            for(int k=i; k<=j; k++){
                int left= helper(i,k-1,balloons, dp); 
                int right=helper(k+1,j,balloons, dp); 

                int coins= balloons[i-1]* balloons[k]* balloons[j+1]; 
                
                int total= left + coins + right; 

                maxcoins= max(maxcoins, total); 
            } 
        return dp[i][j]= maxcoins; 
        }
};