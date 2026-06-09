class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans; 
        unordered_set<int>cols; unordered_set<int>diagonal; unordered_set<int>antidiagonal; 
        vector<string>board(n, string(n,'.')); 
        solve(ans, board, 0, n, cols, diagonal, antidiagonal); 
        return ans;
    }

    void solve(vector<vector<string>>&ans, vector<string> &board, int row, int n, unordered_set<int>cols, unordered_set<int>diagonal, unordered_set<int>antidiagonal){
        if(row==n){
            ans.push_back(board); 
            return; 
        }

        for(int col=0; col<n; col++){
            if(cols.find(col)==cols.end() && diagonal.find(row+col)==diagonal.end() && antidiagonal.find(row-col)==antidiagonal.end()){
                board[row][col]='Q'; 
                cols.insert(col); 
                diagonal.insert(row+col); 
                antidiagonal.insert(row-col); 

                solve(ans, board, row+1, n, cols, diagonal, antidiagonal); 

                board[row][col]='.'; 
                cols.erase(col); 
                diagonal.erase(row+col); 
                antidiagonal.erase(row-col); 

            }
        }
    }

};