class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0; int y=0;
        int dir=0; 

        vector<pair<int,int>>directions{{0,1}, {1,0}, {0,-1}, {-1,0}}; 

        for(char c: instructions){
            if(c=='G'){
                x+= directions[dir].first; 
                y+= directions[dir].second; 
            }
            else if(c=='L'){
                dir= (dir+3)%4; 
            }
            else dir=(dir+1)%4; 
        }

        return ((x==0 && y==0) || dir!=0); 
    }
};