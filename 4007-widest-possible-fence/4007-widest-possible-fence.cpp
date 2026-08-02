class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int>mpp; 
        for(int i: planks){
            mpp[i]++; 
        }
        vector<pair<int,int>>keys; 

        for(auto &i: mpp){
            keys.push_back({i.first, i.second}); 
        }
      
        for(int i=0; i<keys.size(); i++){
            mpp[2*keys[i].first]+= keys[i].second/2; //pair with same
            for(int j=i+1; j<keys.size(); j++){ //distinct elements pair; 
                mpp[keys[i].first+keys[j].first]+= min(keys[i].second, keys[j].second); 
            }
        }

        int ans=0; 
        for(auto &i:mpp){
            ans=max(ans, i.second); 
        }

        return ans; 
    }
};