class Solution {
public:

    int longestStrChain(vector<string>& words) {
        int n=words.size(); 
        sort(words.begin(), words.end(), [](const string &s1,  const string &s2){
            return s1.size()<s2.size(); 
        });

        vector<int>dp(n, 1); 
        int ans=1; 

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(abs(words[i].length()- words[j].length()==1) && check(words[j], words[i])){
                    dp[i]= max(dp[i], 1+ dp[j]); 
                    ans= max(ans, dp[i]); 
                }
            }
        } 

        return ans; 

    }

    bool check(string word1, string word2){
        int n=word1.size(); int m=word2.size(); 
        int i=0; int j=0; int count=0; 
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                i++; j++; 
            }
            else{
                count++; 
                j++; 
            }
        }

        while(j<m){
            count++; 
            j++; 
        }

        if(count>1) return false; 
        return true; 
    }
};