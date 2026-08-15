class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int zeros=0; 

        //entire array is zero
        for(int i:nums){
            if(i==0) zeros++; 
        }
        if(zeros==n) return 0;
        
        int ans=0; 
        for(int i:nums){
            ans=ans^i; 
        }

        if(ans==0) return n-1; 
        else return n;        
    }
};