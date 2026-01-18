class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mpp;    // number, freq 
        vector<int>ans; 

        for(int i=0; i<nums.size(); i++){ 
            mpp[nums[i]]++; 
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>minh; 
        for(auto it= mpp.begin(); it!= mpp.end(); it++){ 
            minh.push({it->second, (-it->first)}); 
        }

        while(!minh.empty()){ 
            for(int i=0; i<minh.top().first; i++){
                ans.push_back({-(minh.top().second)}); 
            }
            minh.pop();
        }
    return ans; 
        
    }
};