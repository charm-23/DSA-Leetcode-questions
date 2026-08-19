class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0; int r=0; int n=s.size(); 
        unordered_map<char, int>mpp; 
        int ans=0; 

        while(r<n){
            mpp[s[r]]++; 
            if(mpp[s[r]]>1){
                while(mpp[s[r]]>1){
                    mpp[s[l]]--; 
                    l++; 
                }
            }
            ans= max(ans, r-l+1); 
            r++; 
        }
        
        return ans; 
    }
};