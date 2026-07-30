class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n=occupiedIntervals.size(); 
        vector<vector<int>>ans; 
        vector<vector<int>>nums; 

        if(n==1) ans=occupiedIntervals; 

        sort(occupiedIntervals.begin(), occupiedIntervals.end()); 

        int start= occupiedIntervals[0][0]; 
        int end= occupiedIntervals[0][1];
        int i=1; 

        while(n!=1 && i<n){
            while(i<n && occupiedIntervals[i][0]<=end+1){
                end=max(end, occupiedIntervals[i][1]); 
                i++; 
            }
            ans.push_back({start,end});

            if(i<n){
                start=occupiedIntervals[i][0];
                end=occupiedIntervals[i][1]; 
            }
        }

        for(int i=0; i<ans.size(); i++){
            int start=ans[i][0]; 
            int end=ans[i][1]; 

            if(start<freeStart && end>freeEnd){
                nums.push_back({start, freeStart-1}); 
                nums.push_back({freeEnd+1, end}); 
            }
            else if(freeEnd<start || end<freeStart) nums.push_back({start,end}); 

            else if(start<freeStart){
                nums.push_back({start, freeStart-1}); 
            }
            else if(end>freeEnd){
                nums.push_back({freeEnd+1, end}); 
            }
        }

        return nums; 
    }
};