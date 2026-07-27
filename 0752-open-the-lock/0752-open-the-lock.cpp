class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>dead; 
        for(string s: deadends){
            dead.insert(s); 
        }

        if(dead.find("0000")!=dead.end()) return -1; 

        unordered_set<string> visited;
        visited.insert("0000");
        string s="0000";
        return helperbfs(s,target, dead, visited); 
    }

    int helperbfs(string s, string target, set<string>&dead,unordered_set<string> &visited){
        queue<string>q; 
        q.push(s); 
        int moves=0;

        while(!q.empty()){
            int size=q.size();

            for(int i=0; i<size; i++){
                string st= q.front(); 
                q.pop(); 
                if(st==target) return moves; 

                for(int i=0; i<4; i++){
                    char original=st[i]; 
                    string temp=st;
                    temp[i]= ((original-'0'+1) %10) +'0'; //forward (0-9 mapping +1 remember)
                    if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                        q.push(temp); 
                        visited.insert(temp); 
                    }
                    temp=st; 
                    temp[i]= ((original-'0'+9) %10) +'0'; //backward (0-9 mapping -1)
                    if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                        q.push(temp); 
                        visited.insert(temp); 
                    }
                }
            }
            moves++; 
        }
        return -1;  
    }
};