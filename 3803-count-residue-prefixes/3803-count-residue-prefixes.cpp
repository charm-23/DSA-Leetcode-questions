class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char, int>mpp; 
        int residue=0; 

        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++; 
            if(mpp.size()==(i+1)%3) residue++; 
        }

        return residue; 
    }
};