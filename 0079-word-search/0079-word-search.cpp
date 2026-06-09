class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=word.size(); 
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0)); 
        int rows= board.size(); int cols= board[0].size(); 
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]==word[0]){
                    if(solve(board, visited,i,j,0, word, rows, cols)){
                        return true; 
                    }
                }
            }
        }
        return false; 
    }

    bool solve(vector<vector<char>>& board,vector<vector<int>>&visited, int row, int col, int i, string word, int rows, int cols){
        if(i==word.size()){
            return true; 
        }

        if(row>=0 && col>=0 && row<rows && col<cols && visited[row][col]==0 && board[row][col]==word[i]){
            visited[row][col]=1;
            if(solve(board, visited, row+1, col, i+1, word, rows, cols) || solve(board, visited, row, col+1, i+1, word, rows, cols) || solve(board, visited, row-1, col, i+1, word, rows, cols) || solve(board, visited, row, col-1, i+1, word, rows, cols)){
                return true; 
            }
            visited[row][col]=0; 
        }
    return false; 
    }
};