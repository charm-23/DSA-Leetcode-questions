class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; //prefixsum, cnt
        mpp[0]=1;

        int prefixsum=0, cnt=0; 

        for(int i=0; i<nums.size(); i++){
            prefixsum+= nums[i]; 
            int left= prefixsum- k;
            cnt+= mpp[left];

            mpp[prefixsum]++; 

        }
        return cnt; 

        
    }
};