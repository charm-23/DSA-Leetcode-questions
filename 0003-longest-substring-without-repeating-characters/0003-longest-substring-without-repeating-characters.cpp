class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0; int r=0; int maxlen=0;
        unordered_map<char,int>mpp; 
        while(r<s.size()){
            mpp[s[r]]++; 
            while(mpp[s[r]]>1){
                mpp[s[l]]--; 
                l++; 
            }
            maxlen= max(maxlen, r-l+1); 
            r++; 
        }
    return maxlen; 
    }
};