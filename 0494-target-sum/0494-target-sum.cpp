class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(); 
        int sum=accumulate(nums.begin(),nums.end(), 0); 

        int subsetsum=(sum+target)/2; //count no. of ways to get subsetsum; 

        if(abs(target)>sum) return 0; 
        if((sum+target)%2!=0) return 0; 

        vector<vector<int>>dp(n, vector<int>(subsetsum+1, 0)); 

        if(nums[0]==0){
            dp[0][0]=2; 
        }
        else dp[0][0]=1;

        if(nums[0]!=0 && nums[0]<=subsetsum) dp[0][nums[0]]=1;

        for(int i=1; i<n; i++){
            for(int sum=0; sum<=subsetsum; sum++){
                int nottake= dp[i-1][sum]; 

                int take=0; 
                if(nums[i]<=sum) take= dp[i-1][sum-nums[i]]; 

                dp[i][sum]= take+nottake; 
            }
        }
        return dp[n-1][subsetsum]; 
    }
};