class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int count=0; 

        for(int i=0; i<n; i++){ 
            if(s[i]-'0'!= i%2){ //odd index=0; even index=1; 010101
                count++; 
            }
        }  

        return min (count, n-count); //010101, 101010
    }
};