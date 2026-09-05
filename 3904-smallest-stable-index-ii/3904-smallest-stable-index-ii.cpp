class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi(nums.size(),-1); 
        maxi[0]=nums[0]; 
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>maxi[i-1]){
                maxi[i]=nums[i]; 
            }
            else{
                maxi[i]=maxi[i-1];
            }
        }

        vector<int>mini(nums.size(),INT_MAX);
        mini[nums.size()-1]=nums[nums.size()-1]; 

        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<mini[i+1]){
                mini[i]=nums[i];
            }
            else{
                mini[i]=mini[i+1]; 
            }
        }

        for(int i=0; i<nums.size(); i++){
            int score= maxi[i]-mini[i]; 
            if(score<=k) return i; 
        }

        return -1; 
    }
};