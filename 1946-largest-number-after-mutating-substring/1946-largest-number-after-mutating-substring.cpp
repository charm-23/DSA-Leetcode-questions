class Solution {
public:
    string maximumNumber(string num, vector<int>& change) { 
        bool start=false; 
        for(int i=0; i<num.size(); i++){
            int index=num[i]-'0';

            if(start==false){
                if(change[index]>index){
                    num[i]=change[index]+'0'; 
                    start=true; 
                }
            } 
            else {
                if(change[index]>=index){
                    num[i]=change[index]+'0'; 
                }
                else break; 
            }
        }
        return num; 
    }
};