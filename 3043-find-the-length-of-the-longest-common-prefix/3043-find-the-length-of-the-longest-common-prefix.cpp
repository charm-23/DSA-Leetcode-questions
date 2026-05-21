class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int cnt=0; 
        unordered_set<int>st;
        for(int i: arr1){
            int num=i; 

            while(num>0){
                st.insert(num); 
                num=num/10; 
            }
        } 

        for(int i: arr2){
            int num=i; 

            while(num>0){
                if(st.find(num)!=st.end()){
                    string n= to_string(num); 
                    int len= n.size();
                    cnt= max(cnt,len); 
                    break; 
                }
                num=num/10; 
            }
        }
    return cnt;
    }
};