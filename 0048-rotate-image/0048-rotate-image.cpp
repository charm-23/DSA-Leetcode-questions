class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //clockwise- tranpose+ reverse each row
        int n=matrix.size(); 
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){ //j=0 cuz it will swap the same elements again
                swap(matrix[i][j], matrix[j][i]); 
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end()); 
        }
       
       //anti-clockwise: transpose+ reverse each column 
       // reverse each column
    //    int rows= matrix.size(); int cols= matrix[0].size(); here both=n; 
    //    for(int j=0; j<cols; j++){
    //     top=0; bottom=rows-1; // these will give the row number 
    //     while(top<bottom){
    //         swap([matrix[top][j], matrix[bottom][j]); 
    //         top++; 
    //         bottom--; 
    //     }
    //    }
    }
};