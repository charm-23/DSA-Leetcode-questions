class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>nums;
        get(candidates,ans,nums,0,target);
        return ans;
    }

    void get(vector<int>& candidates, vector<vector<int>>&ans, vector<int>&nums, int index,int target){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(nums);
                return;
            }
            else return;
       }
       if(candidates[index]<=target){
        nums.push_back(candidates[index]);
        get(candidates,ans,nums,index+1,target-candidates[index]);
        nums.pop_back();
       }

       int k=index+1;
       while(k<candidates.size() && candidates[k]==candidates[index]){
        k++;
       }
       get(candidates,ans,nums,k,target);
    }
};