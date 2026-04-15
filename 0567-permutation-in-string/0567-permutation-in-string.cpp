class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0; i<s1.size(); i++){
            freq[s1[i]-'a']++;
        }
        
        int index=0;

        if(s1.size()>s2.size()) return false;

        while(index<=s2.size()-s1.size()){
        int windfreq[26]={0};
        int i=0;
            while(i<s1.size()){
                windfreq[s2[index+i]-'a']++;
                i++;
            }
            index++;
            if(isFreqSame(freq, windfreq)){
                return true;
            }

        }
        return false ;  
    }
};