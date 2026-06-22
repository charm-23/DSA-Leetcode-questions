class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        return helper(n-1, nums, dp);
    }

    int helper(int index, vector<int>&nums, vector<int>&dp){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];  

        int take= nums[index]+ helper(index-2, nums,dp); 
        int nottake= helper(index-1,nums,dp); 

        return dp[index]=max(take, nottake); 
    }
};