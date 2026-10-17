class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n =arr.size(); 
        vector<vector<int>>dp(n, vector<int>(n,2)); 
        int ans=0; 

        unordered_map<int, int>mpp; 
        for(int i=0; i<n; i++){
            mpp[arr[i]]=i; 
        }

        for(int j=1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int target= arr[k]-arr[j]; 
                if(mpp.find(target)!=mpp.end() && mpp[target]<j){
                    dp[j][k]= 1+ dp[mpp[target]][j];         
                    ans= max(ans, dp[j][k]);
                } 
            }
        }
        return ans; 
    }
};