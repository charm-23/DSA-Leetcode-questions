class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mpp; 
        int l=0; int r=0; int m= s.length(); int n= t.length(); 
        if(n > m) return "";

        for(char c: t){
            mpp[c]++; 
        }

        int count= mpp.size(); int ans=INT_MAX; int left=-1; int right=-1; 

        while(r<m){
            if(mpp.find(s[r])!=mpp.end()){
                mpp[s[r]]--; 
                if(mpp[s[r]]==0) count--; 
            }
            if(count==0){
                while(count==0){
                    if(r-l+1 < ans){
                        ans = r-l+1;
                        left=l, right=r; 
                    } 
                    if(mpp.find(s[l])!=mpp.end()){
                        mpp[s[l]]++; 
                        if(mpp[s[l]]>0) count++; 
                    }
                    l++; 
                }
            }
            r++;   
        }
        return ((left==-1 && right==-1)? "": s.substr(left, right-left+1)); 
    }
};