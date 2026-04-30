class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(), bloomDay.end()); int high=*max_element(bloomDay.begin(), bloomDay.end()); 

        if(1LL*m*k>bloomDay.size()) return -1; 

        while(low<high){
            int mid= low+ (high-low)/2; 
            int bouquet=0; 
            int flowers=0; 

            for(int i: bloomDay){
                if(i<=mid){
                    flowers++; 
                    if(flowers==k){
                        bouquet++; 
                        flowers=0;
                    }
                }
                else{
                    flowers=0;
                }
            }
            if(bouquet<m){
                low=mid+1; 
            }
            else{
                high=mid; 
            }
        }
    return low; 
    }
};