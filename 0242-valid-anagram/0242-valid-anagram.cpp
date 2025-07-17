class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false; 
        int sfreq[26]={0}; 

        for(int i=0; i<s.size(); i++){
            sfreq[s[i]-'a']++;
        }

        int tfreq[26]={0};

        for(int i=0; i<t.size(); i++){
            tfreq[t[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(sfreq[i]!=tfreq[i]) return false;
        }

    return true; 
        
    }
};