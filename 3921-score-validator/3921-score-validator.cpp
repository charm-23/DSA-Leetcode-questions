class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0; int counter=0; 

        for(string i: events){
            if(counter==10) return {score, counter}; 
            if(i=="NB" || i=="WD") score+=1; 
            else if(i=="W"){
                counter+=1; 
            }
            else{
                score+= stoi(i); 
            }
        }
    return {score, counter}; 
    }
};