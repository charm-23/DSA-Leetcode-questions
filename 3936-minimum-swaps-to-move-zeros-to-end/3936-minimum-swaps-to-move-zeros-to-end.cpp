class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero=0; int last=nums.size()-1; int swaps=0; 
        while(zero<nums.size() && nums[zero]!=0){
                zero++; 
        }
        while(last>=0 && nums[last]==0) last--; 

        while(last>=0 && zero<nums.size() && zero<last){
            swap(nums[zero], nums[last]); 
            swaps++; 
            while(zero<nums.size() && nums[zero]!=0){
                zero++; 
            }
            while(last>=0 && nums[last]==0) last--;
        }
        return swaps; 
    }
};