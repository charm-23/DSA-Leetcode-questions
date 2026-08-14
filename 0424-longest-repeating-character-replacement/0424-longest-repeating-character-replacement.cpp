class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0; int r=0; 
        int highestfreq=0; 
        int ans=0; int len=0;
        vector<int>freq(26,0);  

        while(r<s.size()){
            freq[s[r]-'A']++; 
            highestfreq= max(highestfreq, freq[s[r]-'A']); 

            if((r-l+1)-highestfreq>k){
                while((r-l+1)-highestfreq>k){
                    freq[s[l]-'A']--; 
                    int newhigh=0; 
                    for(int i=0; i<26; i++){
                        newhigh= max(newhigh, freq[i]); 
                    }
                    highestfreq= newhigh; 
                    l++; 
                }
            }
            else{
                ans= max(ans, r-l+1); 
            }
            r++; 
        }
        return ans;
    }
};