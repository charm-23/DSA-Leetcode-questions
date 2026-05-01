class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0; 
        for(int i:weights) sum+=i; 
        int low=*max_element(weights.begin(), weights.end()); int high= sum; //low= max element 

        while(low<high){
            int mid= low+ (high-low)/2; 
            int capacity=0; 
            int daycount=1;  

            for(int i:weights){
                if(capacity+i<=mid){
                    capacity+=i;
                }
                else{
                    daycount++;
                    capacity=i;
                }
            }

            if(daycount<=days){
                high=mid;
            }
            else{
                low=mid+1; 
            }

        }
    return low;
    }
};