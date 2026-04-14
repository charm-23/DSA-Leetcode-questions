class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp; 
        int i=0; int j=0; int len=0; 

        while(j<s.size()){
            mpp[s[j]]++; 

            if(mpp[s[j]]==1){
                len= max(len,j-i+1); 
            }
            else{
                while(mpp[s[j]]!=1){
                    mpp[s[i]]--; 
                    i++; 
                }
            }
            j++; 
        }
    return len;
    }
};