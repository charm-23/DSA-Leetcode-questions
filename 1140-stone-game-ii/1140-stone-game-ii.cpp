class Solution {
public:
int dp[100][100][2]; 
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp)); 
        return helper(piles, 0, 1, 0); 
    }

    int helper(vector<int>& piles, int index, int M, bool flag){
        if(index>=piles.size()) return 0; 

        if(dp[index][M][flag]!=-1) return dp[index][M][flag]; 
        int res;
        int stones=0; 

        if(!flag){
            res=0; 
            for(int x=1; x<=min(2*M, (int)piles.size()-index) ; x++){
                stones+= piles[index+x-1]; 
                res=max(res, stones+helper(piles, index+x, max(M,x), 1)); 
            }
        }

        else{
            res=INT_MAX; 
            for(int x=1; x<=min(2*M,(int)piles.size()-index) ; x++){
                res=min(res, helper(piles,index+x, max(M,x),0)); 
            }
        }
        return dp[index][M][flag]=res; 
    }
};