class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans; 
        sort(nums.begin(), nums.end()); 

        for(int a=0; a<nums.size(); a++){
            if(a>0 && nums[a]==nums[a-1]) continue; 
            long long threesum= (long long)target-nums[a]; //impppppppp

            for(int b=a+1; b<nums.size(); b++){
                if(b>a+1 && nums[b]==nums[b-1]) continue; 

                long long findtwosum= threesum-nums[b]; //impppppp

                int c=b+1; int d=nums.size()-1; 

                while(c<d){

                    if(nums[c]+ nums[d]==findtwosum){
                        vector<int>res={nums[a], nums[b], nums[c], nums[d]}; 
                        ans.push_back(res);

                        c++; d--; 

                        while(c<nums.size() && nums[c]==nums[c-1]) c++; 
                        while(d>=0 && nums[d]==nums[d+1]) d--; 
                    }

                    else if(nums[c]+nums[d]<findtwosum) c++; 

                    else d--; 
                }
            }
        }
        return ans;
    }
};