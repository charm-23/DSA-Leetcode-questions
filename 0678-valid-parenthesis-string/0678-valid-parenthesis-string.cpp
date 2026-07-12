class Solution {
public:
    bool checkValidString(string s) {
        stack<char>openst; 
        stack<char>starst; 
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*'){
                starst.push(i); 
            } 
            if(s[i]=='(') openst.push(i); 
            if(s[i]==')'){
                if(!openst.empty()) openst.pop(); //match
                else{
                    if(!starst.empty()) starst.pop(); 
                    else return false; 
                }
            }
        }
        
        //"(" match with * 
        while(!openst.empty() && !starst.empty()){
            if(openst.top()>starst.top()) return false; 
            openst.pop(); 
            starst.pop(); 
        }

    return openst.empty(); 
    }
};