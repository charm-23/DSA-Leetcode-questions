class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1; int high=*max_element(nums.begin(),nums.end()); 

        while(low<high){
            int mid= low+(high-low)/2; 
            int sum=0; 

            for(int i:nums){
                sum+= ceil((double)i/mid); // ceil(i/mid)== integer division hecne incorrect ceil is always used in floating point numbers, instead of ceil use i+mid-1/mid, or convert int to floating point number then use ceil function. -->(double/mid)== double hence ceil(double).
            }

            if(sum>threshold){
                low=mid+1;
            }
            else{
                high=mid; 
            }

        }
    return low; 
    }
};