class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int>mpp; 
        sort(nums.begin(), nums.end()); 

        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++; 
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]!=nums[i] && mpp[nums[i]]!=mpp[nums[j]]){
                    return {nums[i], nums[j]}; 
                }
            }
        }

        return {-1, -1}; 
    }
};