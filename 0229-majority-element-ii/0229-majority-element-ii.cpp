class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(); 
        unordered_map<int, int>mpp; 
        vector<int>ans; 

        for(int i:nums){
            mpp[i]++; 
        }

        for(auto &i: mpp){
            int key=i.first; 
            int value=i.second; 

            if(value>n/3) ans.push_back(key); 
        }

        return ans; 
    }
};