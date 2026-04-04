class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>>ans; 
       sort(nums.begin(), nums.end()); 

       for(int x=0; x<nums.size(); x++){
        if(x>0 && nums[x]== nums[x-1]) continue;

        int target= -nums[x];
        int i=x+1; 
        int j= nums.size()-1;
    

        while(i<j){

            if(nums[i]+nums[j]==target){

                vector<int>res={nums[x], nums[i], nums[j]};
                ans.push_back(res);  
                i++; 
                j--; 

                while(i<j && nums[i]==nums[i-1]) i++; 
                while(i<j && nums[j]==nums[j+1]) j--; 

            }

            else if(nums[i]+nums[j]<target) i++; 

            else j--; 
        } 
        }
    return ans;
    }
};