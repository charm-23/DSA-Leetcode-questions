class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0; 
        for(int i=0; i<piles.size(); i++) sum+=piles[i]; 
        long long l=1; long long r=sum; 

        while(l<r){
            long long mid= l+(r-l)/2; 
            long long time=0;
            for(auto &x:piles){
                time+= (x+mid-1)/mid; //ceil calculation
            }
            if(time<=h){
                r=mid; 
            }
            else{
                l=mid+1; 
            }
        }
    return l; 
    }
};