class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0; 
        unordered_set<int>mpp; 
        for(int i: nums){
            mpp.insert(i); 
        }
        int ans=1; 
        for(int i: mpp){
            if(mpp.find(i-1)== mpp.end()){
                int cnt=1;
                int x= i; 
                while(mpp.find(x+1)!=mpp.end()){
                    cnt++; 
                    x++; 
                } 
            ans= max(cnt, ans);  
            }
        }
    return ans;    
    }
};