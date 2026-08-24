class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(); 
        int total= accumulate(nums.begin(), nums.end(), 0); 
        if(total%2!=0) return false; 

        vector<vector<int>>dp(n, vector<int>((total/2)+1,-1)); 
        return helper(0, total/2, nums, dp); 
    }
    int helper(int i, int target, vector<int>& nums, vector<vector<int>>&dp){
        if(target==0) return true; 

        if(i==nums.size()) return false; 

        if(dp[i][target]!=-1) return dp[i][target]; 

        bool nottake= helper(i+1, target, nums, dp); 
        bool take=false; 

        if(nums[i]<=target){
            take= helper(i+1, target-nums[i], nums, dp); 
        }

        return dp[i][target]= take || nottake; 
    }
};