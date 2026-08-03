class Solution {
public:
    int dp[101][101][2]; 

    int stoneGameII(vector<int>& piles) {
        int n=piles.size(); 
        memset(dp, -1, sizeof(dp)); 
        return helper(piles, 0, 1,0); 
    }

    int helper(vector<int>& piles, int i, int M, bool flag){
        if(i>=piles.size()) return 0; 

        if(dp[i][M][flag]!=-1) return dp[i][M][flag]; 

        int result; 
        int stones=0;

        if(!flag){
            result=-1; 
            for(int x=1; x<=min(2*M, (int)piles.size()-i); x++){ 
                stones+= piles[x+i-1]; 
                result= max(result, stones + helper(piles, i+x, max(M,x),1));
            }
        }
        else{
            result=INT_MAX; 
            for(int x=1; x<=min(2*M, (int)piles.size()-i); x++){ 
                result= min(result, helper(piles, i+x, max(M,x),0));
            }
        }

        return dp[i][M][flag]=result; 
    }
};