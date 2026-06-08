class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans; 
        vector<string>board(n, string(n,'.')); 
        solve(ans, board, 0, n); 
        return ans;
    }

    bool isSafe(vector<string> &board, int row, int col, int n){
        int temp_row=row; 
        int temp_col= col; 

        //straight up
        while(row>0){
            if(board[row-1][col]=='Q') return false; 
            row--; 
        }
        
        row= temp_row; 
        col= temp_col; 

        //diagonal left
        while(row>0 && col>0){
            if(board[row-1][col-1]=='Q') return false; 
            row--; 
            col--; 
        }

        row= temp_row; 
        col= temp_col; 

        // diagonal right
        while(row>0 && col<n-1){
            if(board[row-1][col+1]=='Q') return false; 
            row--; 
            col++; 
        }

        return true; 
    }

    void solve(vector<vector<string>>&ans, vector<string> &board, int row, int n){
        if(row==n){
            ans.push_back(board); 
            return; 
        }

        for(int col=0; col<n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col]='Q'; 
                solve(ans, board,row+1, n); 
                board[row][col]='.'; 
            }
        }
    }

};