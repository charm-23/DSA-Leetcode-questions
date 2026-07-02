class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(); 
        int maxlen=0;
        int start=0; 
        //odd length
        for(int i=0; i<n; i++){
            int l=i; 
            int r=i; 
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1; 
                    start=l; 
                }
                l--; r++; 
            }
        }

        //even length
        for(int i=0; i<n-1; i++){
                int l=i;
                int r=i+1; 
                while(l>=0 && r<n && s[l]==s[r]){
                    if(r-l+1>maxlen){
                        maxlen=r-l+1; 
                        start=l; 
                    } 
                    l--; r++; 
                }
        }
    return s.substr(start,maxlen); 
    }
};