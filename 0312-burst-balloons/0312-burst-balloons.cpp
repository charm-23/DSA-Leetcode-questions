class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //O(n^3)
        int n=nums.size(); 
        vector<int>balloons(n+2,1); 
        vector<vector<int>>dp(n+2, vector<int>(n+2,-1));

        for(int i=0; i<nums.size(); i++){
            balloons[i+1]= nums[i];
        }

        return helper(balloons, 1, n,dp); 
    }

    int helper(vector<int>&balloons, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0; 

        if(dp[i][j]!=-1) return dp[i][j]; 
        int maxcoins=0; 
        for(int k=i; k<=j; k++){
            int left= helper(balloons, i, k-1,dp); 
            int right= helper(balloons, k+1, j,dp); 

            int coins= left+ right+ (balloons[i-1]*balloons[k]*balloons[j+1]); 
            maxcoins= max(maxcoins, coins); 
        }
        return dp[i][j]= maxcoins; 
    }
};