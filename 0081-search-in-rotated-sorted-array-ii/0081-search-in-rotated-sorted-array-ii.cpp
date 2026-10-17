class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size(); 
        if(n==1) return nums[0]==target;
        if(nums[0]==target || nums[n-1]==target) return true; 

        int low=1; int high=n-2; 

        while(low<high && nums[low]==nums[high]){
            if(nums[low]==target) return true; 
            low++; high--; 
        }

        while(low<=high){
            int mid= low+ (high-low)/2; 

            if(nums[mid]==target) return true; 
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]) high=mid-1; 
                else low=mid+1; 
            }
            else{
                if(nums[mid+1]<=target && target<=nums[high]) low=mid+1; 
                else high=mid-1; 
            }
        }

        return false; 

    }
};