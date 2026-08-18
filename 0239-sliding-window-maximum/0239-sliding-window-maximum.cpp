class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq; 
        int l=0; int r=0; 
        vector<int>ans; 
        

        while(r<nums.size()){
           if(dq.empty()) dq.push_back(nums[r]); 
           else{
            if(nums[r]>dq.front()){
                while(!dq.empty()) dq.pop_back();
            }
            while(!dq.empty() && dq.back()<nums[r]) dq.pop_back(); 
            dq.push_back(nums[r]); 
           }

            if(r-l+1==k){
                ans.push_back(dq.front()); 
                if(nums[l]==dq.front()) dq.pop_front(); 
                l++; 
            }

            r++; 
        }

        return ans; 
    }
};