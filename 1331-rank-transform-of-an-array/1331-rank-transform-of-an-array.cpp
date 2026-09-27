class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>minh; 

        for(int i=0; i<arr.size(); i++){
            minh.push({arr[i], i}); 
        }

        int rank=1; int prev=INT_MAX; 

        while(!minh.empty()){
            int val= minh.top().first; 
            int index= minh.top().second;

            if(prev==INT_MAX){
                arr[index]=1;
                prev=val; 
            }
            else{
                if(prev==val){
                    arr[index]=rank; 
                }
                else{
                    rank++; 
                    arr[index]=rank; 
                    prev=val; 
                }
            }

            minh.pop(); 

        }
        return arr; 
    }
};