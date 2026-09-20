class Solution {
public:
    int reverseDegree(string s) {
        vector<int>arr(26, 0); 
        int ans=0; 

        for(char c: s){
            arr[(c-'a')]= 26-(c-'a'); 
        }

        for(int i=0; i<s.size(); i++){
            ans+= (i+1)*(arr[s[i]-'a']);
        }

        return ans; 
    }
};