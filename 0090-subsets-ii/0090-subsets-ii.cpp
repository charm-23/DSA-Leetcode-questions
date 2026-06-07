class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>>ans;
        vector<int>op; 
        solve(nums,0, ans, op); 
        return ans; 
    }

    void solve(vector<int>& nums, int index, vector<vector<int>>&ans, vector<int>&op){
        if(index==nums.size()){
            ans.push_back(op); 
            return;
        }

        op.push_back(nums[index]); 

        solve(nums, index+1, ans, op); 
       
        op.pop_back(); 

        int i= index+1;
        while(i<nums.size() && nums[index]==nums[i]){
            i++; 
        }

        solve(nums, i, ans, op); 
    }

};