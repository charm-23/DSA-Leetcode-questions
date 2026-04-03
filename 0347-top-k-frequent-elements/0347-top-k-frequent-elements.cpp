class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // BUCKET SORT
    unordered_map<int, int> mpp;
    for(int i: nums){
        mpp[i]++; 
    } 

    // MAKING BUCKET LIST
      
    vector<vector<int>>freq(nums.size()+1);
    for(auto &x: mpp){
        freq[x.second].push_back(x.first);
    } 
    
    vector<int>ans; 
    for(int i=freq.size()-1; i>=0; i--){
        if(k>0){
            if(!freq[i].empty()){
                int size= freq[i].size(); 
                for(int i: freq[i]){
                    ans.push_back(i);
                }
                k-=size;
            }
        }
        if(k==0) return ans; 
    }
    return ans;
    }
};