class Solution {
public:
//dp stores the minimum cost to reach that index; 
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size(); 
       vector<int>dp(n+1,-1); 
       return helper(n, dp, cost);  
    }

    int helper(int step, vector<int>&dp, vector<int>& cost){
        if(step==0 || step==1) return 0;
        if(dp[step]!=-1) return dp[step]; 
        return dp[step]= min(helper(step-1, dp, cost)+ cost[step-1], helper(step-2, dp, cost)+ cost[step-2]); 
    }
};