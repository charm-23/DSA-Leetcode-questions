class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans; 
        vector<string>res; 
        helper(s,0, res, ans); 
        return ans; 
    }

    void helper(string s, int index, vector<string>&res, vector<vector<string>>&ans){ 
        if(index==s.length()){
            ans.push_back(res); 
            return; 
        }
        
        string n=""; 
        for(int i=index; i<s.length(); i++){
            n+=s[i];
            int high=n.size()-1; 
            if(isPalindrome(n,0,high)){
                res.push_back(n); 

                helper(s, i+1, res, ans); 

                res.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int low, int high){
        if(low>high) return true; 

        if(s[low]==s[high]){
            return isPalindrome(s, low+1, high-1); 
        }
        
        else{
            return false; 
        }
    }
};