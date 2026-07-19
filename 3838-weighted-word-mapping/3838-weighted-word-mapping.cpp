class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans=""; 
        for(string s: words){
            int weight=0;
            for(int i=0; i<s.length(); i++){
                weight+= weights[s[i]-'a']; 
            }
            weight= weight%26; 

            ans+= ('z'- weight); 
        }
        return ans;
    }
};