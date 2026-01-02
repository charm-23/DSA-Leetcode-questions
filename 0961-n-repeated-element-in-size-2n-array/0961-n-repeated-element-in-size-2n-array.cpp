class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n= nums.size()/2;
        sort(nums.begin(), nums.end()); 
        int cnt=1; int i=1;  

        while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                cnt++; 
                if(cnt==n) return nums[i]; 
            }
            else{
                cnt=1; 
            }
            i++;
        }
    return -1;   
    }
};