class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true; 
        for(int shift=0; shift<s.size(); shift++){
            int temp=s[0]; 
            for(int i=1; i<s.size(); i++){
                s[i-1]=s[i]; 
            }
            s[s.size()-1]=temp; 
            if(s==goal) return true; 
        }
    return false; 
    }
};