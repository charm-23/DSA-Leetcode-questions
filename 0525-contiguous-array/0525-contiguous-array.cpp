class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //sum=0; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) nums[i]=-1; 
        }
        unordered_map<int, int>mpp; 
        mpp[0]=-1; int ans=0;

        int r=0; int sum=0; 
        while(r<nums.size()){
            sum+=nums[r]; 

            if(mpp.find(sum)!=mpp.end()){
                ans= max(ans, r-mpp[sum]); 
            }
            else{
                mpp[sum]=r; 
            }
            r++;
        }
        return ans;
    }
};