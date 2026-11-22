class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans; 
        string s=""; 

        helper(s, n, n, n, ans); 
        return ans; 
    }

    void helper(string s, int n, int o, int c, vector<string>&ans){
        if(o==0 && c==0){
            ans.push_back(s); 
        }

        if(o>0){
            helper(s+'(', n, o-1, c, ans); 
        }

        if(c>o){
            helper(s+')', n, o, c-1, ans); 
        }
    }
};