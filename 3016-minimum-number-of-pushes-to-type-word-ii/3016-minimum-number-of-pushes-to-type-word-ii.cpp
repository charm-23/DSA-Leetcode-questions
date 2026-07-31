class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int>mpp; 
        for(char c: word){
            mpp[c]++; 
        }
        vector<int>freq;

        for(auto &it:mpp){
            freq.push_back(it.second); 
        } 

        sort(freq.rbegin(), freq.rend()); 
        long long ans=0; 
        int i=0; 
        int push=1; 

        while(i<freq.size()){
            for(int j=i; j<i+8; j++){
                if(j<freq.size()) ans+= push*freq[j]; 
            }
            push++; 
            i=i+8;
        }
        return (int)ans;
    }
};