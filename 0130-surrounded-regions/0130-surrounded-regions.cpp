class Solution {
public:

void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, int dx[], int dy[]){
    visited[row][col]=1; 

    int rows= board.size(); 
    int cols= board[0].size(); 

    for(int k=0; k<4; k++){
        int ni= row+ dx[k]; 
        int nj= col+ dy[k]; 

        if(ni>=0 && ni<rows && nj>=0 && nj<cols && !visited[ni][nj] && board[ni][nj]=='O'){
            dfs(ni, nj, board, visited, dx,dy);
        }
    }

}

    void solve(vector<vector<char>>& board) {
        int rows= board.size(); 
        int cols= board[0].size(); 
        vector<vector<int>>visited(rows,vector<int>(cols,0)); 
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        //first row
        for(int i=0; i<cols; i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0, i, board, visited,  dx, dy);
            }
        }

        //last row 
        for(int i=0; i<cols; i++){
            if(!visited[rows-1][i] && board[rows-1][i]=='O'){
                dfs(rows-1, i, board, visited, dx, dy);
            }
        }

        for(int j=0; j<rows; j++){
            if(!visited[j][0] && board[j][0]=='O'){
                dfs(j, 0, board, visited, dx,dy);
            }
        }

        for(int j=0; j<rows; j++){
            if(!visited[j][cols-1] && board[j][cols-1]=='O'){
                dfs(j, cols-1, board, visited,  dx, dy);
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X'; 
                }
            }
        }
        
    }
};