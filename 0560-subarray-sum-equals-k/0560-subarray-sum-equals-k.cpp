class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mpp; // cummulative sum, freq; 
        int cnt=0; 
        mpp[0]=1; 
        int sum=0; 

        for(int i=0; i<n; i++){
            sum+= nums[i]; 
            if(mpp.find(sum-k)!= mpp.end()){
                cnt+=mpp[sum-k]; 
            }
            mpp[sum]++; 
        }
    return cnt;     
    }
};