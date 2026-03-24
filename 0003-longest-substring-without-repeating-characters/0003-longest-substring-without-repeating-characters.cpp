class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length= 0; 
        for(int j=0; j<s.size(); j++){
            int cnt=0; 
            map<char,int> mpp; 
            for(int i=j; i<s.size(); i++){
                if(mpp[s[i]]>=1){
                    length= max(length, cnt);
                    break;
                }
                cnt++; 
                mpp[s[i]]++;
            }
        length= max(length,cnt); 
        }
    return length;  
    }
};