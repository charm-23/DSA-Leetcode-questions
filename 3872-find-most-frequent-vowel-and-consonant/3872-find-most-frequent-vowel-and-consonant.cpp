class Solution {
public:
    int maxFreqSum(string s) {
        int vowfreq=0; 
        int confreq=0; 
        vector<int>freq(26,0); 

        for(int i=0; i<s.length(); i++){
            freq[s[i]-'a']++; 
        }

        for(int i=0; i<26; i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                vowfreq= max(vowfreq, freq[i]); 
            }
            else{
                confreq= max(confreq, freq[i]);
            }

        }
    return confreq+ vowfreq;     
    }
};