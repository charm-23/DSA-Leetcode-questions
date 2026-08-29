class Solution {
public:

    static bool mycomp(string &word1, string &word2){
        return word1.size()<word2.size(); 
    }


    int longestStrChain(vector<string>& words) {
        int n=words.size(); 
        sort(words.begin(), words.end(), mycomp);
        vector<vector<int>>dp(n, vector<int>(n+1, -1)); 
        return helper(0, -1, words, dp); 

    }

    int helper(int i, int prev, vector<string>& words,  vector<vector<int>>&dp){
        if(i==words.size()) return 0; 

        if(dp[i][prev+1]!=-1) return dp[i][prev+1]; 

        int take=0; 

        if(prev==-1 || ((words[i].length()-words[prev].length())==1)&& check(words[prev], words[i])){
            take= 1+ helper(i+1, i, words, dp); 
        }

        int nottake= helper(i+1, prev, words, dp); 

        return dp[i][prev+1]= max(take, nottake); 
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