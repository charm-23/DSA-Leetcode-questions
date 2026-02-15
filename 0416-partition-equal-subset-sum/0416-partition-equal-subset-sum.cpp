class Solution {
public:
// memoization 
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
        }
        if(sum%2 !=0) return false; 

        int target= sum/2; 
        vector<vector<int>>dp(n, vector<int>(target+1,-1)); 

        return helper(nums, 0, 0, sum/2, dp); 
    } 

    bool helper(vector<int>& nums, int i, int curr,int target, vector<vector<int>>&dp){
        if(curr==target) return true; 
        if(i==nums.size() || curr>target) return false; 

        if(dp[i][curr]!=-1) return dp[i][curr]; 

        // trying to taking element 
        bool take= helper(nums, i+1, curr+ nums[i], target, dp);  

        // without that element
        bool skip= helper(nums, i+1, curr, target, dp); 

        if(take || skip){
            dp[i][curr]= 1; 
        }
        else{
            dp[i][curr]= 0; 
        }

    return dp[i][curr]; 
    }

    //bool is implicitly converted into int whenever required 
    // matrix= int cuz of three states {-1,0,1}; 
    // 1== true, 0== false automatically :)) 
};