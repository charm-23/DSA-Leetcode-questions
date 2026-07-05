class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int totalsum=0; 
        for(int i: nums){
            totalsum+=i; 
        }
        if(totalsum%2!=0) return false; 
        vector<vector<int>>dp(nums.size(), vector<int>((totalsum/2)+1,-1)); 
        return helper(nums, 0, totalsum/2, dp); 
    }

    bool helper(vector<int>& nums, int i, int sum, vector<vector<int>>&dp){
        if(sum==0) return true; 
        if(i==nums.size()) return false; 

        if(dp[i][sum]!=-1) return dp[i][sum]; 

        bool take= false; 
        if(nums[i]<=sum){
            take= helper(nums, i+1, sum-nums[i],dp); 
        }
        bool nottake= helper(nums, i+1, sum, dp); 

        return dp[i][sum]= take|| nottake; 
    }
};