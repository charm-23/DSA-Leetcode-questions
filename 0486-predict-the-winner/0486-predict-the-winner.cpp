class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
       int total= accumulate(nums.begin(), nums.end(), 0);
       int n=nums.size(); 
       vector<vector<int>>dp(n, vector<int>(n, -1)); 
       int p1= helper(nums, 0, nums.size()-1, dp); 
       int p2= total-p1; 
       return p1>=p2; 
    }

    int helper(vector<int>& nums, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0; 

        if(dp[i][j]!=-1) return dp[i][j]; 
        int take_i= nums[i]+ min(helper(nums, i+2, j,dp), helper(nums,i+1, j-1, dp)); 
        int take_j= nums[j]+ min(helper(nums, i, j-2, dp), helper(nums,i+1, j-1, dp)); 

        return dp[i][j]=max(take_i, take_j); 
    }
};