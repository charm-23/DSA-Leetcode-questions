class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s= countAndSay(n-1);
        
        return compress(s);
    }

    string compress(string s){
        string t= "";
        int i=0;
        while(i<s.size()){
            int count=0;
            int j=i; 
            while(s[i]==s[j]){
                i++; 
                count++; 
            }
            t+=to_string(count);
            t+=s[j];
        }
    return t; 
    }
};