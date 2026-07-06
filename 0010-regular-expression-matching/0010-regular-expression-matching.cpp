class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0); 
    }

    bool helper(string &s, string &p, int i, int j){
        if(i==s.length() && j==p.length()) return true; 
        if(j==p.length()) return false; 

        bool notconsider= false;  bool consider=false; 
        if(j+1<p.length() && p[j+1]=='*'){
            notconsider= helper(s,p,i,j+2); 

            if(i<s.length() && (s[i]==p[j] || p[j]=='.')){
                consider= helper(s,p,i+1,j); 
            }
        }

        else if(i<s.length() && (s[i]==p[j] || p[j]=='.')) return helper(s, p, i+1, j+1); 

        return consider|| notconsider; 
    }
};