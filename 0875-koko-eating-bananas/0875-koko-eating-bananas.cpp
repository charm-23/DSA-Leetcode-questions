class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; 
        int high= *max_element(piles.begin(), piles.end()); 

        while(low<high){
            int mid= low+ (high-low)/2; 

            int calc=0; 

            for(int i :piles){
                calc+= ((i+mid-1)/mid);
            }

            if(calc<=h) high=mid; 
            else low= mid+1; 
        }
        return low; 
    }
};