class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans; 
        ans.push_back(first(nums, target)); 
        ans.push_back(last(nums, target)); 

        return ans; 
    }

    int first(vector<int>& nums, int target){
        int first=-1;
        int low=0; int high= nums.size()-1; 

        while(low<=high){ 
            int mid= low+ (high-low)/2; 

            if(nums[mid]==target){
                first=mid; 
                high=mid-1; 
            }
            else if(nums[mid]>target){
                high=mid-1; 
            }
            else{
                low=mid+1; 
            }
        }
        return first; 
    }

    int last(vector<int>& nums, int target){
        int last=-1;
        int low=0; int high= nums.size()-1; 

        while(low<=high){ 
            int mid= low+ (high-low)/2; 

            if(nums[mid]==target){
                last=mid; 
                low=mid+1; 
            }
            else if(nums[mid]>target){
                high=mid-1; 
            }
            else{
                low=mid+1; 
            }
        }
        return last; 
    }
};