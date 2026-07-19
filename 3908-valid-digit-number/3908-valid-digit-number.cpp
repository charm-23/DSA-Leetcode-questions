class Solution {
public:
    bool validDigit(int n, int x) {
        bool found=false; 
        bool first=false; 

        while(n!=0){
            if(n/10==0){
                if(n%10==x) first=true; 
            }

            if(n%10==x) found=true; 
            n=n/10; 
        }

        if(found && !first) return true; 
        else return false; 
    }
};