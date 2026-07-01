class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows= matrix.size();
        int cols= matrix[0].size();

        vector<bool> rowZero(rows, false);
        vector<bool> colZero(cols, false);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]==0){
                    rowZero[i] = true;
                    colZero[j] = true;
                 
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            if(rowZero[i]==true){
                for(int j=0; j< cols; j++){
                    matrix[i][j]=0;
                }
            }  
        }

        for(int j = 0; j < cols; j++) {
            if(colZero[j]==true){
                for(int i=0; i< rows; i++){
                    matrix[i][j]=0;
                }
            }  
        }
        
    }
};