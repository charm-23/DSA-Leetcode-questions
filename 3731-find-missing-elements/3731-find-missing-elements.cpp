class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans; 
        int start= *min_element(nums.begin(), nums.end()); 
        int end= *max_element(nums.begin(), nums.end()); 

        unordered_map<int,int>mpp; 
        for(int i:nums){
            mpp[i]++; 
        }

        for(int i=start; i<=end; i++){
            if(mpp.find(i)==mpp.end()) ans.push_back(i); 
        }

        return ans; 
    }
};