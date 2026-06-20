class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size(); 
        int m= board[0].size(); 
        vector<vector<int>>visited(n, vector<int>(m,0));

        //run bfs for all the edges with O

        for(int j=0; j<m; j++){
            if(board[0][j]=='O'){
                bfs(0, j,board, visited, n, m); 
            }
        }

        for(int j=0; j<m; j++){
            if(board[n-1][j]=='O'){
                bfs(n-1, j,board, visited, n, m); 
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                bfs(i, 0, board, visited, n, m); 
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O'){
                bfs(i,m-1,board, visited, n, m); 
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X'; 
                }
            }
        }
    }

    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&visited, int n, int m){
        visited[i][j]=1; 
        queue<pair<int, int>>q; 
        q.push({i,j}); 

        while(!q.empty()){
            int row=q.front().first; 
            int col=q.front().second; 
            q.pop(); 

            int dx[]={-1,1,0,0}; 
            int dy[]={0,0,-1,1}; 

            for(int k=0; k<4; k++){
                int nr= row+ dx[k]; 
                int nc= col+ dy[k]; 

                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && board[nr][nc]=='O'){
                    visited[nr][nc]=1; 
                    q.push({nr, nc}); 
                }

            }
        }
    }
};