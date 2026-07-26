class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans; 
        int i=0; int j=0; int n=series1.size(); int m=series2.size(); 

        while(i<n && j<m){
            if(series1[i][0]<series2[j][0]){
                int timestamp= series1[i][0]; 
                int value= series1[i][1]+ series2[j][1];
                ans.push_back({timestamp,value}); 
                i++; 
            }
            else if(series1[i][0]>series2[j][0]){
                int timestamp= series2[j][0]; 
                int value= series1[i][1]+ series2[j][1];
                ans.push_back({timestamp,value}); 
                j++;
            }
            else{
                int timestamp= series1[i][0]; 
                int value= series1[i][1]+ series2[j][1];
                ans.push_back({timestamp,value}); 
                i++; j++; 
            }
        }

        while(i<n){
                int timestamp= series1[i][0]; 
                int value= series1[i][1]; 
                ans.push_back({timestamp,value}); 
                i++; 
        }

        while(j<m){
                int timestamp= series2[j][0]; 
                int value= series2[j][1]; 
                ans.push_back({timestamp,value}); 
                j++; 
        }

        return ans; 
        
    }
};