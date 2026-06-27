class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1); 
        return helper(nums,0, dp); 
    }

    int helper(vector<int>&nums, int index, vector<int>&dp){
        if(index>=nums.size()-1) return 0;

        if(dp[index]!=-1) return dp[index]; 

        int mini=INT_MAX; 
        for(int i=1; i<=nums[index]; i++){
            int jumps=helper(nums, index+i,dp); 
            if(jumps!=INT_MAX){
                mini= min(mini, 1+ helper(nums, index+i,dp)); 
            }
        }
    return dp[index]=mini; 
    }
};