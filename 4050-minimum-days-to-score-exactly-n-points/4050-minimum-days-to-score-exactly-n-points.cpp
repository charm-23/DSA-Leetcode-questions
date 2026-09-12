class Solution {
public:
    int minDays(int n) {
        int target=n; 

        int maxday= sqrt(2*n)+10; 
        
        vector<vector<int>>dp(maxday+1, vector<int>(n+1,-1)); 
        
        return helper(1, target, 0, dp); 
    }

    int helper(int day, int target, int score, vector<vector<int>>&dp){
        if(score==target) return 0; 
        if(score>target) return INT_MAX; 

        if(dp[day][score]!=-1) return dp[day][score]; 

        int take= INT_MAX; int skip=INT_MAX; 

        if (score+day<=target){
             int calc= helper(day+1, target, score+day, dp); 

            if(calc!=INT_MAX){
                take= 1+ calc; 
            }     
        }

        if(day!=1){
            int calc2= helper(1, target, score, dp);
            if(calc2!=INT_MAX){
                skip=1+calc2; 
            
            }  
        }

        return dp[day][score]= min(skip,take);        
    }
};


