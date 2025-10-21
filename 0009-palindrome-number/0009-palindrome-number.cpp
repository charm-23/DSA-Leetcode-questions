class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n= s.size(); 
        int p=0; 
        int q=n-1; 

        while(p<=q){ 
            if(s[p]!=s[q]) return false; 
            else{ 
                p++; 
                q--; 
            }
        }

    return true;       
    }
};