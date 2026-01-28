class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for(char i: s){
            ans^= i;
        }

        for(char j: t){
            ans^= j;
        }
    return ans;  
    }
};