class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>dp(n, 1); 
        vector<int> parent(n);
        sort(nums.begin(), nums.end());
        parent[0]=0; 
        int maxi=0; 

        for(int i=1; i<n; i++){
            parent[i]=i; 
            int cnt=0; 
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]= dp[j]+1; 
                    parent[i]=j; 
                }
            }
            if(dp[i]>dp[maxi]) maxi=i; 
        }

        vector<int>ans; 
        while (parent[maxi]!= maxi) {
            ans.push_back(nums[maxi]);
            maxi =parent[maxi];
        }

        ans.push_back(nums[maxi]);

        reverse(ans.begin(), ans.end());
        return ans; 
    }
};