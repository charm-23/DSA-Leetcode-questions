class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]=i;
        }

        for(auto &i: operations){
            int index=mpp[i[0]];
            nums[index]=i[1];
            mpp.erase(i[0]);
            mpp[i[1]]=index;
        }
        
    return nums; 
    }
};