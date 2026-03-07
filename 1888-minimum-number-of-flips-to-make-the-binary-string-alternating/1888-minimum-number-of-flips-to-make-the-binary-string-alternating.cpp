class Solution {
public:
// sliding window + Bit flip

    int minFlips(string s) {
        int n=s.size(); 
        if(n==1) return 0; 
        int left=0; 
        int right=0; 
        string s2= s+s; 
        int flip=INT_MAX; 

        int count0=0; 
        int count1=0;

        while(right<2*n){
            if(s2[right]-'0'!= right%2) count0++;
            else count1++;

            if(right-left+1>n){
                if(s2[left]-'0'!=left%2) count0--; 
                else count1--; 
                left++; 
            }  

            if(right-left+1== n){
                flip= min(flip, min(count1, count0)); 
            }

            right++; 
        }
    return flip; 

    }
};