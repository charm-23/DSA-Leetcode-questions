class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0; 
        if(nums.size()==1) return 1; 
        sort(nums.begin(), nums.end()); 
        int ans=1; 
        int cnt=1; 
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]==1){
                cnt++;
                ans= max(cnt, ans);
            }
            else if(nums[i]-nums[i-1]==0){
                continue; 
            }
            else{
                cnt=1;
            }
        }
    return ans;    
    }
};