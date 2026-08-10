class Solution {
public:
    vector<vector<int>> dp;

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, vector<int>(2, -1));
        return helper(n, 1); 
    }

    bool helper(int n, bool turn){
        if(n==0) return !turn; 

        if(dp[n][turn]!=-1) return dp[n][turn]; 
        
        //alice turn
        if(turn){
            for(int i=n; i>=1; i--){
                if(checkps(i)){
                    if(helper(n-i, false)) return dp[n][turn]=true; 
                }
            }
            return dp[n][turn]=false; 
        }
        //bob turn --> wants alice to lose
        else{
            for(int i=n; i>=1; i--){
                if(checkps(i)){
                    if(!helper(n-i, true)) return dp[n][turn]= false; 
                }
            }
            return dp[n][turn]=true; 
        } 
    }

    bool checkps(int n){
        int root= sqrt(n);
        return root*root==n; 
    }
};