class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mpp; 
        mpp[0]=1; 

         int r=0; int n=nums.size(); 
        int ans=0; 
        int sum=0; 

        while(r<n){
            sum+=nums[r]; 
            if(mpp.find(sum-goal)!=mpp.end()){
                ans+=mpp[sum-goal]; 
            }
            mpp[sum]++; 
            r++; 
        }

        return ans; 
    }
};