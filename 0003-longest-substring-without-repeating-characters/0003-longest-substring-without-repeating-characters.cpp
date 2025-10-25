class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp; 
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxlen=0; 
        int len=0; 

        while (r < n) {  
            if(mpp.find(s[r])!= mpp.end() && mpp[s[r]]>=l) {
                l= mpp[s[r]]+1; 
            }
            len=r-l+1; 
            maxlen= max(maxlen,len); 
            mpp[s[r]]=r; 
            r++; 
        }

        return maxlen;
    }
};
