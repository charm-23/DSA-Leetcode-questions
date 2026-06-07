class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;

        solve(ans, 0, candidates, target, op); 

        return ans;
    }

    void solve(vector<vector<int>>&ans, int index,vector<int>& candidates, int target, vector<int>&op){
        if(target==0){
            ans.push_back(op); 
            return; 
        }

        if(target<0 || index==candidates.size()) return;

        op.push_back(candidates[index]);
        solve(ans, index, candidates, target-candidates[index], op); 

        op.pop_back(); 
        solve(ans, index+1, candidates, target, op); 
    }
};