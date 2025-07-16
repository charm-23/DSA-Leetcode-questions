class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.empty()) return 0;

        for(int start=0; start<haystack.size(); start++){
            int j=0; 
            int i=start;

            while(j<needle.size() && i<haystack.size() && haystack[i]==needle[j]){
                i++; 
                j++;
            }

            if(j==needle.size()){
                return start;
            }
        }
    return -1;
    }
};