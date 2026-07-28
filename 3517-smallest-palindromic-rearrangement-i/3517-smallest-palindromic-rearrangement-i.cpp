class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>freq; 
        for(char c: s){
            freq[c]++;  // Nlogk k=26 -->N
        }

        int n=s.length();
        string ans(n, ' '); 
        int t=0; int j=n-1; 
        char middle= 0; 

        for(auto &i: freq){      // O(N)-->N<=26 -->O(1)
            char ch= i.first; 
            int cnt=i.second;

            for(int k=0; k<cnt/2; k++){       // N/2
                ans[t]=ch;
                t++; 
                ans[j]=ch; 
                j--; 
            }
            if(cnt%2==1) middle=ch; 
        }

        if(middle!=0){
            ans[t]=middle; 
        }

        return ans; 
    }
};

//tc--> O(N)
//SC-->O(K=26)+ O(N)--> O(N)