class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high= accumulate(weights.begin(), weights.end(),0); 
        int low= *max_element(weights.begin(), weights.end()); 

        while(low<high){
            int mid= low+ (high-low)/2;
            int capacity=0; 
            int calcdays=1; 

            for(int i:weights){
                if(capacity+i<=mid){
                    capacity= capacity+i; 
                }
                else{
                    capacity=i; 
                    calcdays++;
                }
            }

            if(calcdays<=days){
                high=mid; 
            }
            else if(calcdays>days){
                low=mid+1;
            }
        }
    return low; 
    }
};