class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>mpp; 
        int ans=0; 

        for(int i=0; i<digits.size(); i++){
            for(int j=0; j<digits.size(); j++){
                if(i==j) continue; 
                for(int k=0; k<digits.size(); k++){
                    if(j==k || i==k) continue; 
                    if(digits[i]==0) continue; 
                    int num= digits[i]*100 + digits[j]*10 + digits[k]; 

                    if(mpp.find(num)==mpp.end() && num%2==0){
                        mpp.insert(num); 
                        ans++; 
                    }
                }
            }
        }

        return ans; 
    }
};