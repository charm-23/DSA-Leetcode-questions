class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>left; 
        multiset<int>right; 
        vector<double>ans; 

        int l=0; int r=0; 
        while(r<nums.size()){
            while(r<nums.size() && r<l+k){
                if(left.empty() || nums[r]<=*left.rbegin()){
                    left.insert(nums[r]); 
                }
                    else{
                right.insert(nums[r]); 
                }
                r++; 
            }

            if(k%2==0){
                while(left.size()!=right.size()){
                    if(left.size()>right.size()){
                        auto it= prev(left.end()); 
                        right.insert(*it); 
                        left.erase(it); 
                    }
                    else{
                        auto it=right.begin(); 
                        left.insert(*it); 
                        right.erase(it); 
                    }
                }
                ans.push_back(((double)*prev(left.end())+ *right.begin())/2.0); 

            }
            else{
                if(left.size()>right.size()+1){
                    while(left.size()-right.size()!=1){
                        auto it=prev(left.end()); 
                        right.insert(*it); 
                        left.erase(it); 
                    }
                }
                else if(right.size()>left.size()){
                    while(left.size()-right.size()!=1){
                        auto it=right.begin(); 
                        left.insert(*it); 
                        right.erase(it); 
                    }
                }
                ans.push_back((double)(*prev(left.end()))); 
            }
            int ele=nums[l]; 

            auto it = left.find(ele);

            if(it != left.end()) {
                    left.erase(it);
                }
            else {
                right.erase(right.find(ele));
            }

            l++; 
        }
        return ans; 
    }
};