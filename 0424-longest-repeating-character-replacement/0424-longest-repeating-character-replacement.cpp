class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(); 
        vector<int> freq(26,0); 
        int l=0; int r=0; int maxlen=0; int maxf=0; 
        while(r<n){
            freq[s[r]-'A']++;
            maxf= max(maxf, freq[s[r]-'A']); 

            if((r-l+1)-maxf<=k){
                maxlen= max(maxlen, r-l+1);
                r++; 
            }

            else if((r-l+1)-maxf>k){
                freq[s[l]-'A']--; 
                l++;
                r++;  
            }
        }
    return maxlen; 
    }
};