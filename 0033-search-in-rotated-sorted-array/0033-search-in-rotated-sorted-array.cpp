class Solution {
public:
    int binarysearch( vector<int> &nums, int target, int low, int high){ 
        int mid= low+ (high-low)/2;

        if(low>high) return -1; 

        if(nums[mid]==target){ 
            return mid; 
        } 

        else if(nums[mid]>target){ 
            return binarysearch(nums, target, low, mid-1); 
        }

        else{ 
            return binarysearch(nums, target, mid+1, high);
        }

    }

    int search(vector<int>& nums, int target) {
        int low=0; int high= nums.size()-1; 

        while(low<=high){
            int mid= low+ (high-low)/2; 

            if(nums[mid]==target) return mid; 

            //left sorted 

            if(nums[low]<=nums[mid]){
                if(nums[low]<= target && target< nums[mid]) high=mid-1;
                else low= mid+1;  
            } 

            //right sorted 

            else{
                if(target> nums[mid] && target<=nums[high]) low= mid+1;
                else high= mid-1; ;
            }

        }
    return -1; 
    }
};