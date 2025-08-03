class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size()) return false;

        if(s==goal){
            vector<int>freq(26,0);
            for(char ch: s){
                freq[ch-'a']++;
                if(freq[ch-'a']>1) return true; 
            }
        }
         
        vector<int>diff; 
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i]) diff.push_back(i);

        }

        if(diff.size()!=2) return false; 

        int a= diff[0]; int b= diff[1];
        swap(s[a], s[b]); 

        return s==goal; 
    }
};