class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>res(nums.size()+1,0); 
        for(int i:nums){
            res[i]=1;
        }

        for(int i=0; i<res.size(); i++){
            if(res[i]==0) return i; 
        }
    return -1;
    }
};