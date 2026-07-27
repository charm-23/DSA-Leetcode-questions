class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num); 
        int n=s.size(); 
        vector<pair<int,int>>largestnum(n); 

        largestnum[n-1]={s[n-1], n-1}; 

        for(int i=n-2; i>=0; i--){
            if(largestnum[i+1].first>=s[i]){
                largestnum[i]={largestnum[i+1].first, largestnum[i+1].second}; 
            }
            else{
                largestnum[i]={s[i], i}; 
            }
        }

        for(int i=0; i<n; i++){
            if(s[i]<largestnum[i].first){
                swap(s[i], s[largestnum[i].second]); 
                break; 
            }
        }

        return stoi(s); 
    }
};