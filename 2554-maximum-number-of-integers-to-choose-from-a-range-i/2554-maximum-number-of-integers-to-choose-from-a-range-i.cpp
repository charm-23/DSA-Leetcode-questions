class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s; 
        for(int i=0; i<banned.size(); i++){
            s.insert(banned[i]); 
        }
        int sum=0; 
        int count=0;

        for(int i=1; i<=n; i++){
            if(sum+i<=maxSum && s.find(i)==s.end()){
                sum=sum+i; 
                count++; 
            }
        }

        return count; 
    }
};