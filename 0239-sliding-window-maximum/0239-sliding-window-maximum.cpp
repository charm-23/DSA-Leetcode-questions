class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0; int r=0; int n=nums.size(); 
        deque<int>dq;
        vector<int>ans;

        while(r<n){
            if(dq.empty()){
                dq.push_back(nums[r]);
            }
            else{
                while(!dq.empty() && dq.back()<nums[r]) dq.pop_back(); 
                dq.push_back(nums[r]); 
            }

            if((r-l+1)==k){
                ans.push_back(dq.front());
                if(nums[l]==dq.front()){
                    dq.pop_front();
                }
                l++; 
            }
        r++; 
        } 
    return ans;  
    }
};