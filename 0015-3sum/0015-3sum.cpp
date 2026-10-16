class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(); 
        sort(nums.begin(), nums.end()); 

        vector<vector<int>>ans; 

        for(int k=0; k<n; k++){
            if(k!=0 && nums[k]==nums[k-1]) continue; 
            int target= -nums[k];

            int i=k+1; 
            int j=n-1; 

            while(i<j){
                if(nums[i]+nums[j]==target){
                    ans.push_back({nums[i], nums[j], nums[k]}); 
                    i++; j--;
                    while(i<n && nums[i]==nums[i-1]) i++; 
                    while(j>k && nums[j]==nums[j+1]) j--; 
                }
                else if(nums[i]+nums[j]<target){
                    i++; 
                }
                else j--; 
            }
        }

        return ans; 
    }
};