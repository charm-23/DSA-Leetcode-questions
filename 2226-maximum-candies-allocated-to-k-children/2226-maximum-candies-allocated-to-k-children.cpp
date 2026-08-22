class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1; int high=*max_element(candies.begin(), candies.end()); 
        long long ans=0; 
        while(low<=high){
            long long mid= low+ (high-low)/2; 

            long long children=0; 

            for(int i=0; i<candies.size(); i++){
                children+=candies[i]/mid; 
            }

            if(children>=k){
                ans=mid;
                low=mid+1; 
            }
            else high=mid-1; 
        }
        return (int)ans; 
    }
};