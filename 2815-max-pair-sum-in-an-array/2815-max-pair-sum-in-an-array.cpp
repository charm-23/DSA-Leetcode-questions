class Solution {
public:
    int maxSum(vector<int>& nums) {
       unordered_map<int, int>mpp; 
       int ans=0; 
       int largestdigit= helper(nums[0]);
       mpp[largestdigit]=nums[0];

       for(int j=1; j<nums.size(); j++){
        int largestdigit= helper(nums[j]); 
        if(mpp.find(largestdigit)!=mpp.end()){
            ans=max(ans, nums[j]+ mpp[largestdigit]); 
        }

        if(mpp.find(largestdigit)==mpp.end() || mpp[largestdigit]<nums[j]){
            mpp[largestdigit]=nums[j]; 
        }
       }

       return ans==0? -1: ans; 
    }

    int helper(int num){
        int ans=0; 
        while(num!=0){
            ans= max(ans, num%10); 
            num=num/10; 
        }
        return ans; 
    }
};