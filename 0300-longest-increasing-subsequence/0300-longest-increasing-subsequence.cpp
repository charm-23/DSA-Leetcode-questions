class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(); 
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); 
        return helper( 0, -1, nums, dp); 
    }

    int helper(int i, int prev,vector<int>& nums, vector<vector<int>>&dp){
        if(i==nums.size()) return 0;

        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev]; 

        int nottake= helper(i+1, prev, nums, dp); 
        int take=0; 

        if(prev==-1 || nums[i]>nums[prev]){
            take= 1+ (helper(i+1, i, nums, dp )); 
        }

        if(prev==-1) return max(take, nottake); 

        return dp[i][prev]=max(take, nottake); 
    }
};