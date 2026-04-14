class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0; int j=0; int ans=0; 
        unordered_map<int,int>mpp; 
        while(j<fruits.size()){
            mpp[fruits[j]]++; 
            if(mpp.size()<=2){
                ans= max(ans, j-i+1); 
            }
            else if(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                i++; 
            }
            j++;
        }
        return ans;      
    }
};