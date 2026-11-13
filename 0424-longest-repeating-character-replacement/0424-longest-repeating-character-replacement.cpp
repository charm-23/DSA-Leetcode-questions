class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0); 
        int n=s.size(); 

        int l=0; int r=0; int ans=0; 
        int maxf=0; 

        while(r<n){
            freq[s[r]-'A']++; 
            maxf= max(maxf, freq[s[r]-'A']); 

            int len=r-l+1; 

            if(len-maxf>k){
                freq[s[l]-'A']--; 
                l++; 
            }

            ans= max(ans, r-l+1); 
            r++; 
        }

        return ans; 
    }
};