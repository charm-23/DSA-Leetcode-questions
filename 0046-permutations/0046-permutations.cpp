class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        set<int>s;
        vector<int>op;
        solve(ans, nums, s, op); 
        return ans; 
    }

    void solve(vector<vector<int>>&ans, vector<int>&nums, set<int>&s, vector<int>&op){
        if(op.size()==nums.size()){
            ans.push_back(op);
            return; 
        }

        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i])==s.end()){
                op.push_back(nums[i]);
                s.insert(nums[i]); 
                solve(ans, nums, s, op); 
                s.erase(nums[i]);
                op.pop_back(); 
            }
        }
    }

};