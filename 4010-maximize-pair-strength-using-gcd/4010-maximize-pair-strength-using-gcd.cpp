class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0; 
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                long long strength= ((1LL*nums[i])*(1LL*nums[j]))/ pow(gcd(nums[i],nums[j]),2); 
                ans= max(ans, strength); 
            }
        }
        return ans; 
    }
};