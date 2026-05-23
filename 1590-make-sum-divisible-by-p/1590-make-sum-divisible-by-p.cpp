class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0; 
        for(int i:nums) sum+=i; 
        long long target= sum%p;

        if(target==0) return 0; 

        unordered_map<int,int>mpp; 
        int r=0; int sum1=0; int ans=nums.size(); 
        mpp.insert({0,-1}); 
        while(r<nums.size()){
            sum1=(sum1+nums[r])%p;
            int needed= (sum1-target+p)%p; 
            if(mpp.find(needed)!= mpp.end()) ans= min(ans, r-mpp[needed]);
            mpp[sum1]=r; 
            r++;
        }
    return (ans==nums.size()?-1: ans); 
    }
};