class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //2 options-> multiply 3 largest or 2 most negative numbers multiply by largest.
        int n=nums.size(); 
        int opt1= nums[n-1]*nums[n-2]*nums[n-3]; 
        int opt2= nums[0]*nums[1]*nums[n-1]; 

        return opt1>=opt2? opt1: opt2; 
    }
};