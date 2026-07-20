class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size(); 

        vector<int>suffix(n,0); 
        suffix[n-1]=0; 

        for(int i=n-2; i>=0; i--){
            suffix[i]=suffix[i+1] + nums[i+1]; 
        }

        int count=0; 

        for(int i=0; i<n-1; i++){
            if(nums[i]> suffix[i]/(n-i-1)){
                count++; 
            }
        }

        return count; 
    }
};