class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>freq; 
        for(char c: s){
            freq[c]++; 
        }

        int n=s.length();
        string ans(n, ' '); 
        int t=0; int j=n-1; 

        for(auto &i: freq){
            int ch= i.first; 
            int cnt=i.second;

            for(int k=0; k<cnt/2; k++){
                ans[t]=ch;
                t++; 
                ans[j]=ch; 
                j--; 
            }

            i.second=cnt%2;
        }

        for(auto&i: freq){
            if(i.second==1){
                ans[t]=i.first; 
                t++; 
            }
        }

        return ans; 
    }
};