class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mpp; 
        mpp[0]=1; 
        int sum=0; 
        int ans=0; 

        for(int i: nums){
            sum+=i; 
            if(mpp.find(sum-goal)!=mpp.end()){
                ans+=mpp[sum-goal]; 
            }
            mpp[sum]++; 
        }

        return ans; 
    }
};