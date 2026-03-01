class Solution {
public:
    int minPartitions(string n) {
        int ans=0; 
        for(char i:n){
            if(i-'0'>ans) ans= i-'0'; 
        }
        return ans; 
    }
};