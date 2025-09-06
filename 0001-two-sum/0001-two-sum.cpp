class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size(); 
        vector<int>ans; 

        vector<pair<int, int>> arr; 
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i],i}); 
        }

        sort(arr.begin(), arr.end()); 

        int left=0; 
        int right= n-1; 
        while(left<right){
            int sum= arr[left].first + arr[right].first;

            if(sum== target){
                ans.push_back(arr[left].second);
                ans.push_back(arr[right].second);
                break; 
            }

            else if( sum< target){
                left++;
            }

            else{
                right--; 
            }
        }

        return (ans.empty()? vector<int>{-1,-1}: ans);
        
    }

    
};