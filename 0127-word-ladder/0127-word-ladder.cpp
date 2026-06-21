class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>>adjlist;
        set<string>s; 
        int cnt=0; 
    
        for(int i=0; i<wordList.size(); i++){
            if(compare(beginWord, wordList[i])){
                adjlist[beginWord].push_back(wordList[i]); 
                adjlist[wordList[i]].push_back(beginWord); 
            }
        }

        for(int i=0; i<wordList.size(); i++){
            for(int j=i+1; j<wordList.size(); j++){
                if(compare(wordList[i], wordList[j])){
                    adjlist[wordList[i]].push_back(wordList[j]); 
                    adjlist[wordList[j]].push_back(wordList[i]); 
                }
            }
        }

        return bfs(beginWord, endWord, adjlist, cnt, s); 
    }

    bool compare(string s1, string s2){
        int diff=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]) diff++; 
        }

        if(diff==1) return true; 
    return false; 
    }

    int bfs(string beginWord, string endWord, unordered_map<string, vector<string>>&adjlist, int &count, set<string>&s){
        s.insert(beginWord); 
        queue<string>q; 
        q.push(beginWord); 

        while(!q.empty()){
            int size= q.size(); 
            count++; 

            for(int i=0; i<size; i++){
                string source= q.front(); 
                q.pop();

                for(string ngbr: adjlist[source]){
                    if(ngbr==endWord){
                        return count+1; 
                    }
                    else{
                        if(s.find(ngbr)==s.end()){
                            q.push(ngbr); 
                            s.insert(ngbr); 
                        }
                    }
                }
            }
        }
    return 0; 
    }
};