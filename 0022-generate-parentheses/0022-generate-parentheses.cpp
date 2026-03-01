class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans; 
        helper("", n, n, ans);
        return ans; 
    }

    void helper(string s, int o, int c, vector<string>&ans){
        if(c==0 && o==0){
            ans.push_back(s); 
            return; 
        }
        if(o>0) helper(s+ "(", o-1, c, ans); 

        if(c>o) helper(s+ ")", o, c-1, ans); 
    }
};