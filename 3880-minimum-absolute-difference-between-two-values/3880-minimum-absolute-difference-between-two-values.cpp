class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<bool>count2(nums.size(), false); 
        int ans=INT_MAX; 

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==2) count2[i]= true; 
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                for(int j=0; j<nums.size(); j++){
                    if(count2[j]==true){
                        ans= min(abs(i-j), ans); 
                    }
                }
            }
        }

        return ans==INT_MAX? -1: ans;
    }
};