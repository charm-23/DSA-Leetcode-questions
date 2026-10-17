class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int rows= mat.size(); 
       int cols= mat[0].size(); 

       int low=0; int high=cols-1; 

       while(low<=high){
        int mid= low+ (high-low)/2; 
        int maxi=-1; int idx=-1; 

        for(int row=0; row<rows; row++){
            if(mat[row][mid]>maxi) idx=row; 
            maxi= max(maxi, mat[row][mid]); 
        }

        int left= (mid-1>=0? mat[idx][mid-1] : -1); 
        int right= (mid+1<cols? mat[idx][mid+1] : -1); 

        if(mat[idx][mid]>left && mat[idx][mid]>right) return {idx, mid}; 
        if(mat[idx][mid]<left) high=mid-1; 
        else low=mid+1; 

       }

       return {-1, -1}; 
    }
};