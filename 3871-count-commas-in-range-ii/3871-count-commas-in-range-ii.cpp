class Solution {
public:
    long long countCommas(long long n) {
        long long commas=1; 
        long long lower= 1000; 
        long long ans=0; 

        while(lower<=n){
            long long upper= lower*1000-1; 
            if(upper>n) upper=n; 

            long long cntnos= upper-lower+1; 

            ans+= (1LL*cntnos*commas); 

            lower= lower*1000; 
            commas+=1; 
        }

        return ans; 
    }
};