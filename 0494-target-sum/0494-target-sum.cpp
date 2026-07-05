class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(2001,-1)); 
        return helper(nums, target, 0, 0, dp);
    }

    int helper(vector<int>& nums, int target, int i, int sum, vector<vector<int>>&dp){
        if(i==nums.size() && sum==target) return 1;
        if(i==nums.size()) return 0; 

        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000]; 

        return dp[i][sum+1000]= helper(nums, target, i+1, sum+nums[i],dp) + helper(nums, target, i+1, sum-nums[i],dp); 
    }
};