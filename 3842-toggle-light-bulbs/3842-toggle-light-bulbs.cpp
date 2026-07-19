class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans; 
        vector<int>switcho(101, -1); 
        for(int i=0; i<bulbs.size(); i++){
            if(switcho[bulbs[i]]==0 || switcho[bulbs[i]]==-1) switcho[bulbs[i]]=1; 
            else{
                switcho[bulbs[i]]=0; 
            }
        }

        for(int i=1; i<101; i++){
            if(switcho[i]==1) ans.push_back(i); 
        }

        return ans; 
    }
};