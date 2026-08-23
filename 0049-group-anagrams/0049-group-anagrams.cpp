class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans; 
        map<vector<int>, vector<string>> mpp; 
        for(string s:strs){
            vector<int>freq(26,0); 
            for(int i=0; i<s.size(); i++){
                freq[s[i]-'a']++; 
            }
            mpp[freq].push_back(s); 
        }

        for(auto &i: mpp){
            vector<string>vec= i.second; 
            ans.push_back(i.second); 
        }
        return ans; 
    }
};