class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct=1, minproduct=1; 
        int ans=*max_element(nums.begin(), nums.end()); 

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                maxproduct=1, minproduct=1; continue;  
            }
            int temp= maxproduct;
            maxproduct= max(nums[i],max(nums[i]*maxproduct, nums[i]*minproduct));
            minproduct= min(nums[i],min(nums[i]*temp, nums[i]*minproduct));

            ans= max(maxproduct, ans); 
        }
    return ans; 
    }
};