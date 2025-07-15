class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";
        if(strs.size()==1) return strs[0];

        int length=INT_MAX;
        int end=0;
        for(int i=0; i<strs.size()-1; i++){
            int j=i+1;
            int k=0; 

            while(k<strs[i].length() && k<strs[j].length() && strs[i][k]==strs[j][k]){
                k++;
            }

            if(k<length){
                length=k;
            }
            
        }
    if(length==INT_MAX || length==0) return "";
    return strs[0].substr(0,length);   
    }
};