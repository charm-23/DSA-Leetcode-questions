class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int low=0; int high=nums.size()-1; 
        int mid= low+ (high-low)/2; 

        unordered_map<int, int> mpp; 

        for(int i: nums){
            mpp[i]++; 
        }

        if(mpp[nums[mid]]==1) return true; 
        return false; 
    }
};