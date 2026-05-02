class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1; i<=n; i++){
            string s= to_string(i);
            string p=s;
            bool flag= true; 
            for(int k=0; k<s.size(); k++){
                if(s[k]=='2') s[k]='5';
                else if(s[k]=='5') s[k]='2';
                else if(s[k]=='6') s[k]='9';
                else if(s[k]=='9') s[k]='6';
                else if(s[k]=='3'|| s[k]=='4' || s[k]=='7') {
                    flag= false; break;
                }
            }
            if(flag && s!=p) cnt++;
        }
        return cnt;  
    }
};