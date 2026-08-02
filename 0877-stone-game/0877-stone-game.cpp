class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total= accumulate(piles.begin(), piles.end(), 0); 
        int n=piles.size(); 
        vector<vector<int>>dp(n, vector<int>(n,-1)); 
        return (solve(piles, 0, piles.size()-1,dp)>total/2);
    }

    int solve(vector<int>& piles, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0; 
         //game theory--> alice will take maximum one, and bob will take max from the remaining therefore, the remaining which comes to alice will be minimum. 
        if(dp[i][j]!=-1) return dp[i][j]; 

        int take_i= piles[i]+ min(solve(piles, i+2, j,dp), solve(piles, i+1, j-1,dp)); 
        int take_j= piles[j]+ min(solve(piles, i, j-2,dp), solve(piles, i+1, j-1,dp)); 

        return dp[i][j]=max(take_i, take_j); 
    }
    
};