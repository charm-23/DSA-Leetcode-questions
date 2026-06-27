class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>dp(n,-1); 
        dp[n-1]=1; 
        return helper(nums,0,dp); 
    }

    bool helper(vector<int>&nums, int index, vector<int>&dp){
        if(index==nums.size()-1) return dp[nums.size()-1];
        if(dp[index]!=-1) return dp[index];

        for(int i=1; i<=nums[index]; i++){
            if(index+i<nums.size()){
                if(helper(nums, index+i,dp)) return dp[index]=1; 
            }
        }
    return dp[index]=0;
    }
};