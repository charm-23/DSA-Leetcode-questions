class Solution {
public:
    int MOD= 1e9+7; 
    //min adjacent swaps= no. of inversions
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size(); 

        for(int i=0; i<n; i++){
            if(nums[i]<a) nums[i]=1; 
            else if(nums[i]>=a && nums[i]<=b) nums[i]=2; 
            else nums[i]=3; 
        }

        int one=0; int two=0 ; int three=0; long long swaps=0; 

        for(int i=0; i<n; i++){
            if(nums[i]==1) swaps+= two+three; 
            else if(nums[i]==2) swaps+=three; 
            else swaps+=0;

            if(nums[i]==1) one++; 
            else if(nums[i]==2) two++; 
            else three++; 
        }

        return (int)(swaps%MOD); 
    }
};