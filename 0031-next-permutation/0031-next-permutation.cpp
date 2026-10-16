class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return; 
        int i=n-2;

        //towards the end should be smaller element; 
        //first the first decreasing element from the right end;

        while(i>=0 && nums[i]>=nums[i+1]){
            i--; 
        }

        if(i>=0){
            for(int j=n-1; j>i; j--){
                if(nums[j]>nums[i]){
                    swap(nums[i], nums[j]); 
                    break; 
                }
            }
        }

        reverse(nums.begin()+i+1, nums.end()); 
    }
};