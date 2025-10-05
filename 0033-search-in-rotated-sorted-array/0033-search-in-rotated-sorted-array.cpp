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

        //find smallest element 
        int low= 0; 
        int high= nums.size()-1;  

        while(low<high){               //low==high: smallest element right. 
            int mid= low+ (high-low)/2; 

            if(nums[mid]>nums[high]){
                low= mid+1;  
            }
            else {
                high= mid;
            }
            
        }

        int temp= low;

        if(binarysearch(nums,target,0,temp-1)!=-1){
            return binarysearch(nums,target,0,temp-1); 
        }

        else {
            // if(binarysearch(nums,target,temp,nums.size()-1)){
            return binarysearch(nums,target,temp,nums.size()-1); 
        }
        
    }
};