class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0; int f=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            f+= i*nums[i];
        }
        int ans=f; 
        for(int k=0; k<nums.size(); k++){
            int newf= f+sum -n*(nums[n-1-k]); 
            ans= max(newf,ans); 
            f=newf; 
        }
    return ans; 
    }

    //     int ans=0;
    //     for(int i=0; i<nums.size(); i++){
    //         ans= max(ans, function(nums));
    //         int last= nums[nums.size()-1];
    //         for(int i=nums.size()-2; i>=0; i--){
    //             nums[i+1]=nums[i];
    //         }
    //         nums[0]=last;
    //     }
    // return ans;
    // }

    // int function(vector<int>nums){
    //     int sum=0; 
    //     for(int i=0; i<nums.size(); i++){
    //         sum+=i*nums[i];
    //     }
    // return sum;
    // }
};