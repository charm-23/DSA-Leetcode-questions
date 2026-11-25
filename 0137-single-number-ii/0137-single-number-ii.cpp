class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0; 
        for(int k=0; k<=31; k++){ //every bit 

            int temp= (1<<k) ; 
            int countzeroes=0; 
            int countones=0; 

            for(int &num: nums){
                if((num & temp)==0) countzeroes++; 
                else countones++; 

            }
            if(countones%3==1){
                ans= ans | temp; 
            }
        }
        return ans; 
    }
};