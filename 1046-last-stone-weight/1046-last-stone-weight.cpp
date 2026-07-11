class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh; 
        for(int i: stones){
            maxh.push(i); 
        }
        while(maxh.size()>1){
            int stone1= maxh.top(); 
            maxh.pop(); 
            int stone2= maxh.top(); 
            maxh.pop(); 
            if(stone1>stone2) maxh.push(stone1-stone2); 
        }
        if(maxh.empty()) return 0; 
    return maxh.top(); 
    }
}; 