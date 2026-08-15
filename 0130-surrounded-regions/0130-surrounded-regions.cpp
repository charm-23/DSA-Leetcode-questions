class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(); 
        int m=board[0].size(); 

        for(int i=0; i<n; i++){
            if(board[i][0]=='O') bfs(i, 0, n, m, board); 
        }

        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O') bfs(i, m-1, n, m, board); 
        }

        for(int j=0; j<m; j++){
            if(board[0][j]=='O') bfs(0, j, n, m, board); 
        }

        for(int j=0; j<m; j++){
            if(board[n-1][j]=='O') bfs(n-1, j, n, m, board); 
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O') board[i][j]='X'; 
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='1') board[i][j]='O'; 
            }
        }

    }

    void bfs(int i, int j,int n, int m, vector<vector<char>>& board){
        board[i][j]='1'; 
        int dx[]={-1,1,0,0}; 
        int dy[]={0,0,1,-1};

        queue<pair<int,int>>q; 
        q.push({i,j}); 

        while(!q.empty()){
            int x= q.front().first; 
            int y=q.front().second; 
            q.pop(); 

            for(int k=0; k<4; k++){
                int nx= x+ dx[k]; 
                int ny= y+ dy[k]; 

                if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]=='O'){
                    q.push({nx, ny}); 
                    board[nx][ny]='1'; 
                }
            }
        }
    }
};