class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans=0; 
        for(int i=0; i<nums.size(); i++){
            long long sum=0;
            for(int j=i; j<nums.size(); j++){
                sum+=nums[j]; 
                if(check(sum,x)) ans++; 
            }
        }
        return ans;
    }

    bool check(long long sum, int x){
        if(sum%10!=x) return false; 

        while(sum>=10){
            sum=sum/10;
        }

        return sum==x;
    }
};