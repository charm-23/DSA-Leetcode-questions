class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0]; 
        if(n==2) return max(nums[0], nums[1]); 
        return max(helper(nums,0,n-2), helper(nums,1,n-1)); 
    }

    int helper(vector<int>&nums, int firstindex, int lastindex){
        int n=lastindex-firstindex+1; 
        vector<int>dp(n,-1); 
        dp[0]=nums[firstindex];
        if(n==1) return dp[0]; 
        dp[1]=max(nums[firstindex+1],nums[firstindex]); 
        if(n==2) return dp[1];
        for(int i=2; i<n; i++){
            dp[i]=max(nums[firstindex+i]+dp[i-2], dp[i-1]); 
        }
        return dp[n-1]; 
    }
};