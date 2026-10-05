class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(), nums.end()); 
        int high=accumulate(nums.begin(), nums.end(), 0); 

        while(low<high){
            int mid= low+ (high-low)/2;

            if(helper(nums, mid)>k){
                low=mid+1;
            }
            else high=mid; 
        }

        return low; 
    }

    int helper(vector<int>& nums, int maxsum){
        int currsum=0; 
        int parts=1; 

        for(int i=0; i<nums.size(); i++){
            if(currsum+nums[i]<=maxsum){
                currsum= currsum+nums[i]; 
            }
            else{
                parts++; 
                currsum=nums[i]; 
            }
        }
        return parts; 
    }
};