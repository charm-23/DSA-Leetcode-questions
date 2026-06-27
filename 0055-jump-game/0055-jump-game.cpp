class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxfar=0;
        for(int i=0; i<n; i++){
            if(i>maxfar) return false; 
            maxfar= max(maxfar, i+nums[i]); 
            if(maxfar>=n-1) return true; 
        }
        return true; 
    }   
};