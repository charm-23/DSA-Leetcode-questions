class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int i=0;
        int sign=1;

        while(i<s.size() && s[i]==' '){
            i++;
        }

        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        
        while(i<s.size() && isdigit(s[i])){
            ans= (ans*10)+ (s[i]-'0');
            
            if(sign*ans<= INT_MIN) return INT_MIN;
            if(sign*ans >= INT_MAX) return INT_MAX;

            i++;
        }
    return (sign * ans);
        
    }
};