class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int ans=0;
        vector<long long>arr(47,0);

        arr[0]=1; arr[1]=1; 

        for(int i=2; i<47; i++){
            arr[i]= arr[i-1]+ arr[i-2]; 
        }

        while(k>0){
            for(int i=46; i>=0; i--){
                if(arr[i]<=k){
                    ans++; 
                    k=k-arr[i]; 
                }
            }
        }
        return ans;
    }
};