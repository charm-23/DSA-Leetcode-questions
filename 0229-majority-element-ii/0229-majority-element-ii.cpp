class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //moore's voting algorithm

        int element1; int element2; 
        int count1=0; int count2=0; 
        int n=nums.size(); 

        vector<int>ans; 

        for(int i=0; i<nums.size(); i++){
            if(count1==0 && nums[i]!=element2){
                element1=nums[i]; 
                count1++; 
            }
            else if(count2==0 && nums[i]!=element1){
                element2=nums[i]; 
                count2++; 
            }

            else if(nums[i]==element1) count1++; 

            else if(nums[i]==element2) count2++; 

            else{
                count1--; count2--; 
            }
        }

        count1=0; count2=0; 
        for(int num: nums){
            if(num==element1) count1++; 
            else if(num==element2) count2++; 
        }

        if(count1>(n/3)) ans.push_back(element1); 
        if(count2>(n/3)) ans.push_back(element2); 

        return ans; 

    }
};