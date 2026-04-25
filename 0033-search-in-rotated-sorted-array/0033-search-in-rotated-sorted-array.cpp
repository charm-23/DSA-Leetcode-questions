class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0; 
            else return -1; 
        }
        
        int low=0; int high= nums.size()-1; 
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]<nums[i]){
                int split=i;
                if(binarysearch(nums,target,low,split)==-1 && binarysearch(nums,target,split+1,high)==-1) return -1;
                else if(binarysearch(nums,target,low,split)!=-1) return binarysearch(nums,target,low,split); 
                else return binarysearch(nums,target,split+1,high); 
            }
        }
    return binarysearch (nums, target, low, high);
    }

    int binarysearch(vector<int>&nums,int target, int low, int high){
        if(low>high) return -1; 
        while(low<=high){
            int mid=low+(high-low)/2; 
            if(nums[mid]==target) return mid; 
            else if(nums[mid]<target) low=mid+1;
            else high= mid-1; 
        }
    return -1; 
    }
};