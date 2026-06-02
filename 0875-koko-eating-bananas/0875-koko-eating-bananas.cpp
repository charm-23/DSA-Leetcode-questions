class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi= *max_element(piles.begin(), piles.end());
        int low=1; int high= maxi; 

        while(low<high){
            int mid= low+ (high-low)/2; 
            int hrs=0;

            for(int i: piles){
                hrs+= (i+mid-1)/mid;
            }

            if(hrs>h){
                low=mid+1; 
            }
            else{
                high=mid;
            }
        }
    return low; 
    }
};