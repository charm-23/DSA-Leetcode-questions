class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>ans; 
        for(int i=0; i<nums.size(); i++){
            int add=0; 
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]%2==0){
                    if(nums[j]%2!=0) add++; 
                }
                else{
                    if(nums[j]%2==0) add++; 
                }
            }
            ans.push_back(add); 
        }
        return ans; 
    }
};