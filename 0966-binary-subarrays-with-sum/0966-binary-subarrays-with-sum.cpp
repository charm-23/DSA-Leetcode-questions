class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarray(nums, goal)- numSubarray(nums, goal-1); 
    }
    int numSubarray(vector<int>& nums, int goal) {
        int l=0; int r=0; int sum=0; int cnt=0; 
        if(goal<0) return 0; 
        while(r<nums.size()){
            sum+= nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            cnt= cnt+ (r-l+1); 
            r=r+1; 
        }
    return cnt; 
    }

};