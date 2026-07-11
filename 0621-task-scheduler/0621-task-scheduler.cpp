class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0; 
        if(n==0) return tasks.size(); 
        vector<int>freq(26,0); 

        for(char c: tasks){
            freq[c-'A']++; 
        }

        priority_queue<int>pq; 

        for(int i=0; i<26; i++){
            if(freq[i]>0){
                pq.push(freq[i]); 
            }
        }

        while(!pq.empty()){
            vector<int>temp; 
            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int task=pq.top(); 
                    task--; 
                    temp.push_back(task); 
                    pq.pop(); 
                }
            }

            for(int i=0; i<temp.size(); i++){
                if(temp[i]!=0){
                    pq.push(temp[i]); 
                }
            }

            if(pq.empty()){
                time+=temp.size(); 
            }
            else{
                time+=n+1; 
            }
        }

        return time; 
    }
};