class Solution {
public:
    int numberOfSpecialChars(string word) {
      vector<int>lastoccursmall(26,-1); 
      vector<int>firstoccurcapital(26,-1);
      int cnt=0;

      for(int i=0; i<word.size(); i++){
        if(islower(word[i])){
            lastoccursmall[word[i]-'a']=i; 
        }
        else{
            if(firstoccurcapital[word[i]-'A']==-1){
                firstoccurcapital[word[i]-'A']=i; 
            }
        }
      }

      for(int i=0; i<26; i++){
        if(lastoccursmall[i]!=-1 && firstoccurcapital[i]!=-1 &&lastoccursmall[i]<firstoccurcapital[i]) cnt++; 
      }

    return cnt;
    }
};