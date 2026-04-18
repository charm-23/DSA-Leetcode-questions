class Solution {
public:
//by sliding window SC= O(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (maxsum(nums,goal)- maxsum(nums, goal-1));
    }
    long long maxsum(vector<int>& nums, int k){
        if(k < 0) return 0;
        int sum=0; int l=0; int r=0; int cnt=0; 
        while(r<nums.size()){
            sum+= nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1); 
            r++; 
        }
    return cnt; 
    }
};