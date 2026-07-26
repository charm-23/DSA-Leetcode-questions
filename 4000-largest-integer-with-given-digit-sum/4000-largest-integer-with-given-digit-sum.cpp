class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0) return 0; 
        if(s>9*n) return -1; 
        int ans=0; 

        for(int i=n-1; i>=0; i--){
            if(s>=9){
                ans+=9*pow(10,i);
                s=s-9; 
            }
            else{
                ans+=s*pow(10,i); 
                s=0;
            }
        }

        return ans;
    }
};