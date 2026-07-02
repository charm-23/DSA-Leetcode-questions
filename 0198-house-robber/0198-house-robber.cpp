class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0; 
        if(n==1) return nums[0];
        int prev= nums[0]; 
        int prev2=0; 
        int curr; 

        for(int i=1; i<n; i++){
            curr= max(nums[i]+prev2, prev);
            prev2=prev; 
            prev=curr; 
        }
        return curr; 
    }
};