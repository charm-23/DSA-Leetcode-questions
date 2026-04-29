class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int low=0; int high= nums.size()-1; int n=nums.size(); 
        int first=-1; int last=-1; 

        while(low<=high){
            int mid= low+ (high-low)/2; 

            if(nums[mid]==target){
                first=mid; last=mid; 
                while(first>0 && nums[first-1]==target){
                    first--;
                }
                while(last<n-1 && nums[last+1]==target){
                    last++;
                }
                return {first,last};
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return {-1,-1};
    }
};