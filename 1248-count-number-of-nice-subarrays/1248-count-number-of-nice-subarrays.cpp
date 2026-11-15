class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // imagine odd number= 1 , even number 0; 
        //count no of subarrays with sum=k

        unordered_map<int, int>mpp; 
        mpp[0]=1; int r=0; int sum=0; int count=0; int n=nums.size(); 

        while(r<n){
            sum+=(nums[r]%2); 

            if(mpp.find(sum-k)!=mpp.end()) count+=mpp[sum-k]; 

            mpp[sum]++; 
            r++; 
        }
        return count; 
    }
};