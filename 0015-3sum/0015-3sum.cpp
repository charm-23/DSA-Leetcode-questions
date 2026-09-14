class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans; 
        sort(nums.begin(), nums.end()); 

        //nums[i]= -(nums[j]+ nums[k]); 

        for(int k=0; k<nums.size(); k++){

            if(k>0 && nums[k]==nums[k-1]) continue;

            int findsum= -nums[k]; 

            int i=k+1; int j=nums.size()-1;

            while(i<j){

                if(nums[i]+nums[j]==findsum){
                    vector<int>res; 
                    res.push_back(nums[k]); 
                    res.push_back(nums[i]); 
                    res.push_back(nums[j]); 

                    i++; j--; 

                    while(i<nums.size() && nums[i]==nums[i-1]) i++; 
                    while(j>=0 && nums[j]==nums[j+1]) j--; 

                    ans.push_back(res); 
                }

                else if(nums[i]+nums[j]<findsum){
                    i++; 
                }

                else j--; 
            }

        }

        return ans; 
    }
};