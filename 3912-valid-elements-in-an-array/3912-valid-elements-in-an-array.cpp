class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans; 
        ans.push_back(nums[0]); 
        if(nums.size()==1) return ans; 

        int n=nums.size(); 
        vector<int>suffix(n,0); 
        suffix[n-1]= nums[n-1]; 

        for(int i=n-2; i>=0; i--){
            if(nums[i]>suffix[i+1]){
                suffix[i]=nums[i]; 
            }
            else{
                suffix[i]= suffix[i+1]; 
            }
        }

        int leftmax= nums[0]; 

        for(int i=1; i<nums.size()-1; i++){
            if(nums[i]>leftmax){
                ans.push_back(nums[i]); 
                leftmax=nums[i]; 
            }
            else if(nums[i]>suffix[i+1]){
                ans.push_back(nums[i]); 
            }
        }

        ans.push_back(nums[n-1]); 

        return ans; 
    }
};