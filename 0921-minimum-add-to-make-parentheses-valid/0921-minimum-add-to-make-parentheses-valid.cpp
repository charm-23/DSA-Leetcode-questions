class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0; 
        stack<char>st; 
        if(s=="") return 0; 

        for(char c: s){
            if(c=='('){
                st.push('('); 
            }
            else if(!st.empty() && c==')') st.pop(); 
            else{
                count++; 
            }
        }
        return (!st.empty()? count+ st.size(): count); 
    }
};