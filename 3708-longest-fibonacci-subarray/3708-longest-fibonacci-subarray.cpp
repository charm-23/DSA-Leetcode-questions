class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(); 
        if(n==1 || n==2) return n; 
        vector<int>dp(n); 
        dp[0]=1; dp[1]=2; int ans=2; 
        
        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1]+ nums[i-2]) dp[i]= 1+ dp[i-1]; 
            else{
                dp[i]=2; 
            }
            ans= max(ans, dp[i]); 
        }

        return ans; 
    }
};