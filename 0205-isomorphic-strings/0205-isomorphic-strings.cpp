class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!= t.size()) return false; 

        unordered_map<char,char> mpp; 
        unordered_map<char,char> track; 

        for(int i=0; i<s.size(); i++){
            if(mpp.find(s[i])== mpp.end() && track.find(t[i])== track.end()){
                mpp[s[i]]= t[i];
                track[t[i]]= s[i]; 
            }
            else if(mpp[s[i]]!=t[i] ) {
                return false; 
            }
        }
    return true; 
    }
};