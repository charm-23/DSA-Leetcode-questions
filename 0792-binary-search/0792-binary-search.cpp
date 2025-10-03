class Solution {
public:
    
    //iterative 

    // int search(vector<int>& nums, int target) {
    //     int low= 0; 
    //     int high= nums.size()-1;
        
    //     while(low<=high){
    //         int mid= low + (high-low)/2; 
        
    //     if(nums[mid]==target){
    //         return mid; 
    //     }

    //     else if(nums[mid]>target){
    //         high= mid-1; 
    //     }

    //     else{ 
    //         low= mid+1; 
    //     }

    //     }
    // return -1; 
    // }


    //recursive 
    int search(vector<int>& nums, int target){
        return helper(nums, target, 0, nums.size()-1);
    }

    int helper(vector<int>&nums, int target, int low, int high){
        if(low>high) return -1; 

        int mid= low + (high-low)/2; 

        if(nums[mid]==target) return mid; 
        else if (nums[mid]> target) return helper(nums, target, low, mid-1); 
        else return helper(nums,target, mid+1, high); 
    }
};