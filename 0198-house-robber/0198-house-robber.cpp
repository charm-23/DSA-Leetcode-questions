class Solution {
public:
//space optimization
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0; int prev2=0;
        for(int i=0; i<n; i++){
            nums[i]=max(nums[i]+prev2, prev1); 
            prev2=prev1; 
            prev1=nums[i]; 
        }
        return nums[n-1];
    }
};