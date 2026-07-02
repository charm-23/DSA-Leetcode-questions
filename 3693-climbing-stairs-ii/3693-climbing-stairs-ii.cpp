class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==0) return 0;  
        int prev3=0; 
        int prev2= prev3+ costs[0]+1;
        if(n==1) return prev2; 
        int prev1= costs[1]+ min(prev2+1, prev3+4); 
        if(n==2) return prev1; 
        int curr; 

        for(int i=3; i<=n; i++){
           curr = costs[i-1]+ min(prev3+9, min(prev1+1, prev2+4));
           prev3=prev2; 
           prev2=prev1; 
           prev1=curr;
        } 
        return curr; 
    }
};