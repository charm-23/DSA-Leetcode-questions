class Solution {
public:
    static bool compare(pair<char, int>&a, pair<char, int>&b){
        return a.second> b.second; 
    }

    string frequencySort(string s) {
        map<char,int> mpp;        
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++; 
        }

        vector<pair<char,int>> v(mpp.begin(), mpp.end()); 

        sort(v.begin(), v.end(), compare); 

        string ans= ""; 

        for(auto &it: v){
            ans.append(it.second, it.first); 

        }
    return ans; 

    }
};