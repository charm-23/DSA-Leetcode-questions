class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows=board.size(); 
        int cols=rows; 
        int dest=rows*rows; 
        unordered_map<int,int>mpp; 

        int counter=1; 
        bool flag=0; 
        int row=rows-1; 

        vector<int>visited((rows*rows)+1, 0); 

        while(row>=0){
            if(!flag){ 
                for(int col=0; col<cols; col++){
                    if(board[row][col]!=-1){
                        mpp[counter]=board[row][col]; 
                    }
                    counter++; 
                }
                flag=1; 
            }
            else{
                for(int col=cols-1; col>=0; col--){
                    if(board[row][col]!=-1){
                        mpp[counter]=board[row][col]; 
                    }
                    counter++; 
                }
                flag=0; 
            }
            row--;
        }

        queue<int>q; 
        q.push(1);
        int steps=0; 
        visited[1] = 1;

        while(!q.empty()){
            int size=q.size(); 

            for(int i=0; i<size; i++){
                int node= q.front(); 
                if(node==dest) return steps; 
                q.pop(); 

                for(int i=1; i<=6; i++){
                    
                    int next= min(node+i, dest); 

                    if(mpp.find(next)!=mpp.end()){
                        next=mpp[next]; 
                    }

                    if(!visited[next]){
                        visited[next]=1; 
                        q.push(next); 
                    }
                } 
            }
            steps++; 
        }

        return -1; 
    }
};