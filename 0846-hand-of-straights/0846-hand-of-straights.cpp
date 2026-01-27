class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()% groupSize !=0) return false; 

        map<int,int> mpp; //freq 
        for(int i: hand){
            mpp[i]++; 
        }   

        while(!mpp.empty()){
            int start= mpp.begin()->first; 

            for(int i=0; i<groupSize; i++){
                int card= i+ start; 

                if(mpp.find(card)== mpp.end()) return false; 

                mpp[card]--; 

                if(mpp[card]==0) mpp.erase(card);
            }
        }
     return true;
    }
};