class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans; 
        map<int,int> freq; 
        for(int i=0; i<nums.size(); i++){ 
            freq[nums[i]]++; 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh; 

        for(auto it= freq.begin(); it!= freq.end(); it++){
            if(minh.size()<k){
                minh.push({it->second, it->first}); 
            }
            else break; 
        }

        while(!minh.empty()){
            ans.push_back ({minh.top().second});
            minh.pop(); 

        }
      return ans; 
    }
};