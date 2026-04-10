class Solution {
public:
//BRUTE FORCE 
    int lengthOfLongestSubstring(string s) {
        int maxlen=0; 
        for(int i=0; i<s.size(); i++){
            string sub = ""; 
            vector<int>freq(256,0); //all char comes within the ASCII value 0-255
            for(int j=i; j<s.size(); j++){
                if(freq[s[j]]==1) break; 
                sub=sub+ s[j];
                freq[s[j]]++; 
                maxlen= max(maxlen, j-i+1);
            }
        }
    return maxlen; 
    }
};