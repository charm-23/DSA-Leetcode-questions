class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s; 
        return helper(n,s);   
    }

    bool helper(int n, unordered_set<int>&s){
        if(n>0) if(s.find(n)!=s.end()) return false;
        s.insert(n); 
        int sum=0; 
        while(n!=0){
            int digit= n%10; 
            sum+= digit*digit; 
            n=n/10; 
        }
        if(sum==1) return true;

        return helper(sum,s); 
    }
};