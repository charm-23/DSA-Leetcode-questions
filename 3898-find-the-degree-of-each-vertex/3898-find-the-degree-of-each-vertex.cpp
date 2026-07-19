class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans; 
        for(auto &i : matrix){
            int add=0;
            for(int j: i){
                if(j==1) add++; 
            }
            ans.push_back(add); 
        }
        return ans;
    }
};