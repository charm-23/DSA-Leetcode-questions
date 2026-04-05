class Solution {
public:
//SLIDING WINDOW
    int lengthOfLongestSubstring(string s) {
        int maxlen=0; 
        int l=0; int r=0; 
        vector<int>freq(256,0); 

        while(r<s.size()){
            while(freq[s[r]]==1){
                freq[s[l]]--; 
                l++; 
            }
            freq[s[r]]++; 
            maxlen= max(maxlen, r-l+1);
            r++; 
        }

    return maxlen; 
    }
};