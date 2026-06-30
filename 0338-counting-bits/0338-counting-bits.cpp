class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans; 
        for(int i=0; i<=n; i++){
            int sum=0;
            helper(i,sum,ans); 
        }
        return ans; 
    }

    void helper(int n, int &sum, vector<int>&ans){
        if(n==0){
            ans.push_back(sum); 
            return; 
        }
        int binary=n%2; 
        if(binary==1) sum++; 
        helper(n/2, sum, ans); 
    }
};