class Solution {
public:
    string reverseByType(string s) {
        string ans=""; 
        int n=s.length(); 

        int nonletter=s.length()-1; 
        while(nonletter>=0 && isalpha(s[nonletter])){
            nonletter--; 
        }
        
        int letter=s.length()-1; 
        while(letter>=0 && !isalpha(s[letter])){
            letter--; 
        }

        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i])){
                ans+=s[letter];
                letter--;
                while(letter>=0 && !isalpha(s[letter])){
                    letter--; 
                }
            }
            else{
                ans+=s[nonletter];
                nonletter--; 
                while(nonletter>=0 && isalpha(s[nonletter])){
                    nonletter--; 
                }
            }
        }
        return ans;
    }
};