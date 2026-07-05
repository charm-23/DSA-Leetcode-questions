class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        int ans=1; 
        vector<vector<int>>dp(n,vector<int>(n+1,-1)); 
        return helper(nums, n, 0, -1, ans, dp); 
    }

    int helper(vector<int>&nums, int n, int i, int prev, int &ans, vector<vector<int>>&dp){
        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1]; 
        
        int take=0; 
        if(prev==-1 || nums[i]>nums[prev]){
            take= 1+ helper(nums, n, i+1, i, ans, dp); 
        }
        int nottake= helper(nums,n, i+1, prev,ans,dp);

    return dp[i][prev+1]= max(take, nottake); 
    }
};