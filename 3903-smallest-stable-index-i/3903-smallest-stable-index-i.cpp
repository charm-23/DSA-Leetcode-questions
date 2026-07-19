class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(); 
        vector<int>suffix(n, INT_MAX); 

        suffix[n-1]=nums[n-1]; 

        for(int i=n-2; i>=0; i--){
            suffix[i]= min(nums[i], suffix[i+1]); 
        }

        int leftmax=nums[0]; 

        for(int i=0; i<nums.size(); i++){
            leftmax= max(leftmax, nums[i]); 
            if((leftmax- suffix[i])<=k) return i; 
        }
        return -1; 
    }
};