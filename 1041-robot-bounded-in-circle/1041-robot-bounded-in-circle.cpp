class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0; int y=0; char face= 'n'; 
        for(int i=0; i<instructions.size(); i++){
            if(instructions[i]=='G'){
                if(face=='n') y++; 
                else if(face=='s') y--; 
                else if(face=='e') x++; 
                else x--; 
            }
            else if(instructions[i]=='L'){
                if(face=='n') face='w'; 
                else if(face=='w') face='s'; 
                else if(face=='s') face='e'; 
                else face='n'; 
            }
            else{
                if(face=='n') face='e'; 
                else if(face=='e') face='s'; 
                else if(face=='s') face='w'; 
                else face='n'; 
            }
        }
        if((x==0 && y==0) || face!='n') return true; 
        else return false; 
    }
};