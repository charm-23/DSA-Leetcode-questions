class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st; 
        int l=0, r=0; 
        int n=s.size(); 
        int ans=0;

        while(r<n){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]); 
                l++; 
            }
            ans= max(ans, r-l+1); 
            st.insert(s[r]); 
            r++; 
        }
        return ans; 
    }
};