class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mpp; 
        for(char c: s){
            mpp[c]++; 
        }
        sort(s.begin(), s.end(), [&mpp](const char &a, const char &b){
            if(mpp[a]!=mpp[b]) return mpp[a]>mpp[b];
            return a>b; 
        });

        return s; 
    }
};