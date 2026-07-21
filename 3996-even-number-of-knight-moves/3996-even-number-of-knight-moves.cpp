class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int n=8; 
        vector<vector<bool>>visited(8, vector<bool>(8,false)); 

        int r=start[0]; int c=start[1]; 
        visited[r][c]=true; 
        int targetx= target[0]; int targety= target[1]; 

        return helper(r, c, targetx, targety, 0, visited); 

    }

    bool helper(int r, int c, int targetx, int targety, int moves, vector<vector<bool>>&visited){
        if(moves%2==0 && r==targetx && c==targety) return true; 
        else if(r==targetx && c==targety) return false; 

        int dx[]={-2,-2,-1,1,2,2,1,-1};
        int dy[]={-1,1,2,2,1,-1,-2,-2};

        for(int i=0; i<8; i++){
            int nr= r +dx[i];
            int nc= c +dy[i]; 

            if(nr<8 && nr>=0 && nc<8 && nc>=0 && visited[nr][nc]==false){
                visited[nr][nc]=true; 
                if(helper(nr, nc, targetx, targety, moves+1, visited)) return true;
            }
        }

        return false;
    }
};