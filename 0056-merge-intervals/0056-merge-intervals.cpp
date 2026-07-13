class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size(); 

        if(intervals.size()==0 || intervals.size()==1) return {intervals}; 
        int i=1; 
        sort(intervals.begin(), intervals.end()); 

        int start= intervals[0][0]; 
        int end= intervals[0][1]; 

        while(i<n){
            while(i<n && intervals[i][0]<=end){
                end= max(end, intervals[i][1]); 
                i++;
            }

            ans.push_back({start,end});

            if(i<n){
                start= intervals[i][0]; 
                end= intervals[i][1];
            }
        }
    return ans; 
    }
};