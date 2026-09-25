class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq; 

        for(int i: stones){
            pq.push(i); 
        }

        while(pq.size()>1){
            int stone1= pq.top(); 
            pq.pop(); 
            int stone2= pq.top(); 
            pq.pop(); 

            int diff= abs(stone1-stone2); 
            if(diff>0) pq.push(diff); 
        }

        if(pq.size()==1) return pq.top(); 
        return 0; 
    }
};