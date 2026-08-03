class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int total=accumulate(stoneValue.begin(), stoneValue.end(), 0); 
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        int alice= helper(stoneValue, 0, 0,dp); 
        int Bob= total-alice; 

        if(alice>Bob) return "Alice"; 
        else if(alice==Bob) return "Tie"; 
        else return "Bob"; 
    }
    //alice -->alice max, bob-->bob max, worst for alice

    int helper(vector<int>& stoneValue, int i, bool flag, vector<vector<int>>&dp){
        if(i>=stoneValue.size()) return 0; 
        int score=0; 
        int res; 

        if(dp[i][flag]!=-1) return dp[i][flag]; 

        //alice turn
        if(!flag){
            res=INT_MIN;
            for(int x=1; x<=3; x++){
                if(i+x-1<stoneValue.size()){
                    score+=stoneValue[i+x-1];
                    res= max(res, score+ helper(stoneValue, i+x, true,dp)); 
                }
            }
        }
        else{
            res=INT_MAX;
            for(int x=1; x<=3; x++){
                if(i+x-1<stoneValue.size()){
                    res= min(res, helper(stoneValue, i+x, false,dp)); //worst case left for alice, after bob selected its maximum; 
                }
            }
        }
        return dp[i][flag]=res; 
    }
};