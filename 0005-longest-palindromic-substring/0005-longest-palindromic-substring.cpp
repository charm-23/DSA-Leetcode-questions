class Solution {
public:
    string longestPalindrome(string s) {
        int start=0; 
        int maxlength=0;
        string ans= "";

        
        while(start<s.length()){
            int end= s.size()-1;
            while(end>=start){
                if(s[start]==s[end] && end-start+1>maxlength){
                    int temp1=start;
                    int temp2=end;
                    bool isPalindrome=true;

                    while(temp1<=temp2){
                        if(s[temp1]!=s[temp2]){
                            isPalindrome=false;
                            break;
                        }
                        temp1++;
                        temp2--;
                    }

                    if(isPalindrome){
                        maxlength=end-start+1;
                        ans= s.substr(start,end-start+1);
                    }

                }    
                end--;
            }
            start++;
        }
        return ans;
        
        
    }
};