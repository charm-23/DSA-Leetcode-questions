class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct=1, minproduct=1;
        vector<int>dp(nums.size()+1);
        dp[0]=1; 
        int ans= *max_element(nums.begin(), nums.end()); 

        for(int i=1; i<=nums.size(); i++){
            if(nums[i-1]==0){
                minproduct=1; 
                dp[i]=1; 
            }
            dp[i]= max(minproduct*nums[i-1],max(nums[i-1], dp[i-1]*nums[i-1])); 
            minproduct= min(minproduct*nums[i-1],min(nums[i-1], dp[i-1]*nums[i-1])); 
            ans= max(ans, dp[i]); 
        }

    return ans; 
    }
};