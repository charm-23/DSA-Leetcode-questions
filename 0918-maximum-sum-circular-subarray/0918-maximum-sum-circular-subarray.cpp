class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(); 
        //circular max sum= totalsum- minsum; 
        int totalsum= accumulate(nums.begin(), nums.end(), 0); 

        //case1-> maxsum is in linear= maxkadane; 
        //case2-> minsum is in linear, maxsum sum is circular= minkadane; 
        //so maxcircularsum=total-minkadane; 

        if(maxkadane(nums)<0) return maxkadane(nums); //all negatives; 

        return max(maxkadane(nums), totalsum-minkadane(nums)); 
    }

    int maxkadane(vector<int>&nums){
        int n= nums.size(); 
        int ans= INT_MIN; 
        int sum=0; 

        for(int i=0; i<n; i++){
            sum+=nums[i]; 
            ans=max(ans, sum); 

            if(sum<0) sum=0; 
        }

        return ans; 
    }

    int minkadane(vector<int>&nums){
        int n=nums.size(); 
        int sum=0; 
        int ans=INT_MAX; 

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            ans=min(ans,sum); 

            if(sum>0) sum=0;
        }
        return ans; 
    }
};