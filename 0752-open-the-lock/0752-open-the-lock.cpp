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
                    string temp=st; 
                    if(st[i]=='0'){
                        temp[i]='9'; 
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            q.push(temp);
                            visited.insert(temp); 
                        }
                        temp[i]='1'; 
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            q.push(temp); visited.insert(temp); 
                        }
                    }
                    else if(st[i]=='9'){
                        temp[i]='0';
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            q.push(temp); visited.insert(temp); }
                        temp[i]='8'; 
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            q.push(temp); visited.insert(temp); }
                    }
                    else{
                        temp[i]++; 
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            q.push(temp); visited.insert(temp); }
                        temp[i]=temp[i]-2; 
                        if(dead.find(temp)==dead.end() && visited.find(temp)==visited.end()){
                            visited.insert(temp); q.push(temp); 
                        } 
                    }
                }
            }
            moves++; 
        }
        return -1;  
    }
};