class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(); 
        unordered_set<string>st; 
        vector<int>dp(n+1,-1); 
        for(string x: wordDict){
            st.insert(x); 
        }
        return helper(s,0,st,n,dp); 
    }

    bool helper(string s, int i, unordered_set<string>&st, int n, vector<int>&dp){
        if(i==n) return true; 
        if(st.find(s.substr(i))!=st.end()) return true; 
        
        if(dp[i]!=-1) return dp[i]; 
        string s1="";
        for(int index=i; index<n; index++){
            s1+=s[index]; 
            bool take=false; 
            if(st.find(s1)!=st.end()){
                if(helper(s,index+1,st,n,dp)) return dp[i]=true; 
            }
        }
    return dp[i]=false; 
    }

};

