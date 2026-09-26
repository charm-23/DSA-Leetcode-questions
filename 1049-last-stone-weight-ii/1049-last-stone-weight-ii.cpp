class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size(); 

        int sumi=accumulate(stones.begin(), stones.end(), 0); 

        int target=sumi/2;

        vector<vector<bool>>dp(n, vector<bool>(target+1, false)); 

        for(int i=0; i<n; i++){
            dp[i][0]=true; 
        }

        if(stones[0]<=target) dp[0][stones[0]]=true; 

        for(int i=1; i<n; i++){
            for(int sum=1; sum<=target; sum++){
                bool nottake= dp[i-1][sum]; 

                bool take=false; 
                if(stones[i]<=sum) take= dp[i-1][sum-stones[i]]; 

                dp[i][sum]= take || nottake; 
            }
        }

        for(int i=target; i>=0; i--){
            if(dp[n-1][i]==true) return abs((2*i)-sumi); 
        }

        return 0;
    }
};