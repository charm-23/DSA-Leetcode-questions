class Solution {
public:
// n-1Ck-1 - n-k-2/2 C k-1
// all- odd 
// stars and bars 
    const int MOD= 1e9+7; 
    vector<long long>fact; 
    vector<long long>invfact; 

    long long power(long long base, long long exp){
        long long res=1; 
        while(exp>0){
            if(exp%2==1){
                res=(res*base)%MOD; 
            }
            base= (base*base)%MOD; 
            exp= exp/2; 
        }
        return res;
    }


    void calculatefact(int n){
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0]=1; 

        for(int i=1; i<=n; i++){
            fact[i]=(fact[i-1]*i)%MOD; 
        }
        invfact[n]=power(fact[n], MOD-2);  
        for(int i=n; i>=1; i--){
            invfact[i-1]= (invfact[i]*i)%MOD; 
        }
    }

    long long nCr(int n, int r){
        if(r<0 || r>n) return 0; 

        long long ans= fact[n]; 
        ans= ans*invfact[r]%MOD; 
        ans= ans*invfact[n-r]%MOD; 
        return ans; 
    }


    int countValidSequences(int n, int k) {
        calculatefact(n); 
        long long totalways= nCr(n-1, k-1); 

        if((n-k)%2!=0){
            return totalways; 
        }

        int remaining= (n-k)/2; 
        long long oddways= nCr(remaining + k-1, k-1); 

        long long ans= totalways-oddways; 
        if(ans<0){
            ans+=MOD;
        }

        return ans; 
    }
};