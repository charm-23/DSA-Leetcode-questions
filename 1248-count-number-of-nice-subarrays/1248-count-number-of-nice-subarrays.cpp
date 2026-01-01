class Solution {
public:
    //(sum<=goal)
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

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1; 
        }
         return numSubarray(nums, k)- numSubarray(nums, k-1); 
    }
};