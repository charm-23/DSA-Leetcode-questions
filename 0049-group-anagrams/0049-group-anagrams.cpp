class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans; 
        map<vector<int>, vector<string>>mpp; 

        for(int i=0; i<strs.size(); i++){
            vector<int>freq(26,0);
            for(char c:strs[i]){
                freq[c-'a']++; 
            }
            mpp[freq].push_back(strs[i]); 
        }

        for(auto &p:mpp){
            ans.push_back(p.second); 
        }
        return ans;  
    }
};