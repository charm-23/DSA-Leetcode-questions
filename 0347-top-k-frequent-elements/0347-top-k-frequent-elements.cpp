class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans; 

        unordered_map<int, int> mpp; 
        for(int i:nums){
            mpp[i]++; 
        }
        vector<pair<int,int>>freq; 

        for(const auto& i: mpp){
            freq.push_back({i.second, i.first}); 
        }
        sort(freq.rbegin(), freq.rend());  //sort(freq.begin(), freq.end(), greater<pair<int,int>>());

        for(int i=0; i<k; i++){
            ans.push_back(freq[i].second); 
        }
    return ans;
    }
};