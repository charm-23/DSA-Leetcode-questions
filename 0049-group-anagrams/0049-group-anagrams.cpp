class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp; 
        for(int i=0; i<strs.size(); i++){
            vector<int>freq(26,0);  //replacing sorting= TC=O(N*klogk)--> TC=O(N*k); 
            for(char c: strs[i]){
                freq[c-'a']++; 
            }
            mpp[freq].push_back(strs[i]);
        }

    vector<vector<string>>ans; 
    for(auto& p: mpp){
        ans.push_back(p.second);
    }
    return ans; 
    }
};