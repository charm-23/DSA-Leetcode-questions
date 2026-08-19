class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=0; 
        unordered_map<int, vector<int>>mpp; 
        for(auto &i: reservedSeats){
            int row= i[0]; int seat= i[1]; 
            mpp[row].push_back(seat); 
        }

        for(auto &it: mpp){
            int row=it.first; 
            vector<int>seats= it.second; 
            vector<int>arr(11,0); 
            for(int i: seats){
                arr[i]=1; 
            }
            bool g1=true; 
            for(int i=5; i>=2; i--){
                if(arr[i]!=0){g1=false; 
                break;}
            }

            bool g2=true; 
            for(int i=7; i>=4; i--){
                if(arr[i]!=0) {g2=false; 
                break; }
            }

            bool g3=true; 
            for(int i=9; i>=6; i--){
                if(arr[i]!=0) {g3=false; 
                break; }
            }

            if(g1 && g3) ans= ans+2; 
            else if(g1 || g3) ans=ans+1; 
            else if(!g1 && !g3 && g2) ans++; 
        }
        ans+= (n-mpp.size())*2; 

        return ans; 
    }
};