class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size(); 
        if(s==goal) return true;

        if(s.size()==goal.size()){
            for(int rot=0; rot<n; rot++){
                char ch= s[0];
            for(int i=1; i<n; i++){
                s[i-1]=s[i];
            }
            s[n-1]=ch;
            if(s==goal) return true;
            }
        }
        return false;
    }
};