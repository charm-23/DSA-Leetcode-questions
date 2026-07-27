class Solution {
public:
    int myAtoi(string s) {
        int num=0; 
        int n=s.length(); 
        int i=0; 
        bool negative=false; 
    
        while(i<n && s[i]==' '){
            i++; 
        }

        if(i<n && s[i]=='-'){
            negative=true; 
            i++; 
        }
        else if(i<n && s[i]=='+')i++;

        while(i<n && s[i]=='0') i++; 

        while(i<s.length() && isdigit(s[i])){
            if(negative==false && num>(INT_MAX-(s[i]-'0'))/10){
                return INT_MAX;
            }
            else if(negative==true && num>(INT_MAX-(s[i]-'0'))/10){
                return INT_MIN; 
            }
            num=num*10+(s[i]-'0'); 
            i++; 
        }

        return negative==true? -num: num ; 
    }
};