class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(); 
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) nums[i]=-1; 
        }

        unordered_map<int, int>mpp; //cumulative sum, index
        int sum=0; 
        int ans=0; 
        mpp[0]=-1; 

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i]; 
            if(mpp.find(sum)!=mpp.end()){
                ans= max(ans, i-mpp[sum]); 
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i; 
            }
        }

        return ans; 
    }
};