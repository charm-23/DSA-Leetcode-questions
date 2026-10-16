class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //3 choices--> number itself, multiply number with minimum of previous subarray, multiply number with maximum of previous subarray; 
        int n=nums.size(); 

        int ans=INT_MIN; int mini=1; int maxi=1; 

        for(int i=0; i<nums.size(); i++){
            int temp= mini; 
            mini= min(nums[i]*maxi,min(nums[i], nums[i]*mini)); 
            maxi= max(nums[i]*maxi,max(nums[i], nums[i]*temp)); 

            ans= max(ans, maxi); 
        }

        return ans; 
    }
};