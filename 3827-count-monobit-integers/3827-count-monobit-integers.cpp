class Solution {
public:
    int countMonobit(int n) {
        int count=1; 

        for(int x=1; x<10; x++){
            if(pow(2,x)-1<=n) count++;
            else break;  
        }

        return count;
    }
};