class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1; long long r=(long long)*min_element(time.begin(),time.end())*totalTrips; 

        while(l<r){
            long long mid= l+(r-l)/2;
            long long trips=0; 
            for(int i:time) trips+= mid/i; 

            if(trips<totalTrips){
                l=mid+1; 
            }
            else{ //trips>=totalTrips
                r=mid;
            }
        }
    return l; 
    }
};