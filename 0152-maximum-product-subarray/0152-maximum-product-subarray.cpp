class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini=1, maxi=1; 
        int ans=*max_element(nums.begin(), nums.end()); 
        for(int i=0; i<nums.size(); i++){
            int temp=mini; 
            mini= min(min(mini*nums[i], maxi*nums[i]),nums[i]); 
            maxi= max(max(temp*nums[i], maxi*nums[i]),nums[i]); 
            ans=max(ans,maxi);
        }
        return ans; 
    }
};