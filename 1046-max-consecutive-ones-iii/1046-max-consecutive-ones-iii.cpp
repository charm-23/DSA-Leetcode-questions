class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size(); 
        int l=0; int r=0; int maxlen=0; int cnt=0; 

        while(r<n){
            if(nums[r]==0 && k>0){ 
                k--; 
            }

            else if(nums[r]==0 && k==0){
                while(nums[l]==1) l++; 
                l++; 
                k++; 
                continue; 
            }

            cnt= r-l+1; 
            maxlen= max(maxlen,cnt); 
            r++; 
        }
    return maxlen;  
    }
};