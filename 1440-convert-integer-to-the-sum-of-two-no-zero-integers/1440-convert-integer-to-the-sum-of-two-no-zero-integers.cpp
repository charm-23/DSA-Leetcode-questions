class Solution {
public:

    bool nozero(int num){
        while(num>0){
            if(num%10==0) return false; 
            num=num/10; 
        }
    return true; 
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans; 

        for(int i=1; i<=n/2; i++){
            int a=i; 
            int b= n-a; 

            if(nozero(a) && nozero(b)){
                ans.push_back(a);
                ans.push_back(b);
                break; 
            }
        }
    return ans; 
    }
};