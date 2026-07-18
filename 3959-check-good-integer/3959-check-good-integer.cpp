class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum=0; 
        int squaresum=0; 
        while(n!=0){
            digitsum+=n%10; 
            squaresum+= (n%10)* (n%10); 

            n=n/10; 
        }
        return squaresum-digitsum>=50? true: false; 
    }
};