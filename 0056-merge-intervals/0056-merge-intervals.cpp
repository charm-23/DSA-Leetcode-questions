class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        vector<vector<int>>ans; 
        if(intervals.size()==1) return intervals;

        int i=0; 
        int n=intervals.size();
        int start; int end; 

        while(i<n){
            start=intervals[i][0];
            end=intervals[i][1];

            while(i<n && intervals[i][0]<=end){
                end=max(end, intervals[i][1]); 
                i++; 
            }
            ans.push_back({start,end}); 
        }

        return ans; 
    }
};