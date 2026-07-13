class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size(); 
        int i=1; int count=0; 
        sort(intervals.begin(),intervals.end()); 

        int start=intervals[0][0]; 
        int end=intervals[0][1]; 

        while(i<n){
            if(intervals[i][0]<end){
                end=min(end, intervals[i][1]);
                count++; 
                i++;
            }
            else{
                start=intervals[i][0]; 
                end=intervals[i][1]; 
                i++;
            }
        }
    return count;
    }
};